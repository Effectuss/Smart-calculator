#include "mathCalc.h"

inline const std::map<std::string, std::function<double(double)>>
    MathCalc::kFunctions_{
        {"sin", [](double val) -> double { return sin(val); }},
        {"cos", [](double val) -> double { return cos(val); }},
        {"tan", [](double val) -> double { return tan(val); }},
        {"acos", [](double val) -> double { return acos(val); }},
        {"asin", [](double val) -> double { return asin(val); }},
        {"atan", [](double val) -> double { return atan(val); }},
        {"sqrt", [](double val) -> double { return sqrt(val); }},
        {"ln", [](double val) -> double { return log(val); }},
        {"log", [](double val) -> double { return log10(val); }}};

inline const std::map<std::string, std::function<double(double, double)>>
    MathCalc::kOperators_{
        {"+", [](double val1, double val2) -> double { return val1 + val2; }},
        {"-", [](double val1, double val2) -> double { return val2 - val1; }},
        {"/", [](double val1, double val2) -> double { return val2 / val1; }},
        {"*", [](double val1, double val2) -> double { return val1 * val2; }},
        {"^",
         [](double val1, double val2) -> double { return pow(val2, val1); }},
        {"mod",
         [](double val1, double val2) -> double { return fmod(val2, val1); }},
        {"A", [](double val1, double val2) -> double { return val2 + val1; }},
        {"C", [](double val1, double val2) -> double { return val2 - val1; }}};

double MathCalc::ShuntingYard(std::string &str_from_label, const double &x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());
  std::stack<double> stack_number;
  std::stack<Token> stack_operations;
  auto current_token = this->tokenizator_.GetListToken().begin();
  while (current_token != this->tokenizator_.GetListToken().end()) {
    if (current_token->IsNumber()) {
      stack_number.push(std::stod(current_token->GetTokenString()));
      ++current_token;
    } else if (!(current_token->IsOpenParenthesis() ||
                 current_token->IsCloseParenthesis())) {
      if (current_token->IsUnaryOperator()) {
        stack_number.push(0.0);
      }
      if (!stack_operations.size()) {
        stack_operations.push(*current_token);
        ++current_token;
      } else if ((current_token->GetPriority() >
                      stack_operations.top().GetPriority() ||
                  (current_token->GetTokenString() == "^" &&
                   current_token->GetPriority() >=
                       stack_operations.top().GetPriority()))) {
        stack_operations.push(*current_token);
        ++current_token;
      } else if (current_token->GetPriority() <=
                 stack_operations.top().GetPriority()) {
        CountValue(stack_operations, stack_number);
      }
    }
    if (current_token != this->tokenizator_.GetListToken().end()) {
      if (current_token->IsOpenParenthesis()) {
        stack_operations.push(*current_token);
        ++current_token;
      } else if (current_token->IsCloseParenthesis()) {
        while (stack_operations.top().GetTokenString() != "(") {
          CountValue(stack_operations, stack_number);
        }
        ++current_token;
        stack_operations.pop();
      }
    }
  }
  while (!stack_operations.empty()) {
    CountValue(stack_operations, stack_number);
  }
  return stack_number.top();
}

void MathCalc::CountValue(std::stack<Token> &stack_operations,
                          std::stack<double> &stack_number) {
  double tmp = stack_number.top();
  stack_number.pop();
  if (stack_operations.top().GetType() == Token::TypeTokens::kFunction) {
    tmp = kFunctions_.at(stack_operations.top().GetTokenString())(tmp);
  } else {
    tmp = kOperators_.at(stack_operations.top().GetTokenString())(
        tmp, stack_number.top());
    stack_number.pop();
  }
  stack_number.push(tmp);
  stack_operations.pop();
}
