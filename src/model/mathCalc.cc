#include "mathCalc.h"

namespace s21 {

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
        {"-", [](double val1, double val2) -> double { return val1 - val2; }},
        {"/", [](double val1, double val2) -> double { return val1 / val2; }},
        {"*", [](double val1, double val2) -> double { return val1 * val2; }},
        {"^",
         [](double val1, double val2) -> double { return pow(val1, val2); }},
        {"mod",
         [](double val1, double val2) -> double { return fmod(val1, val2); }},
        {"A", [](double val1, double val2) -> double { return val1 - val2; }},
        {"C", [](double val1, double val2) -> double { return val1 + val2; }}};

double MathCalc::ShuntingYard(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());
  std::stack<double> stack_number;
  std::stack<std::string> stack_operators;
  auto current_token = this->tokenizator_.GetListToken().begin();
  while (current_token != this->tokenizator_.GetListToken().end()) {
    if (current_token->IsNumber()) {
      stack_number.push(std::stod(current_token->GetTokenString()));
    }
  }
  return 0.0;
}

}  // namespace s21