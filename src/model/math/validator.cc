#include "validator.h"

namespace s21 {
void Validator::Validation(std::list<Token>& tokens) {
  if (Validator::ValidForFirst(tokens.front())) {
    int count_open_parenthesis = 0;
    int count_close_parenthesis = 0;
    auto current = tokens.begin();
    if (current->IsOpenParenthesis()) ++count_open_parenthesis;
    auto previous = tokens.begin();
    ++current;
    while (current != tokens.end()) {
      if ((*current).IsNumber()) {
        ValidForNumber(*previous);
      } else if ((*current).IsFunction()) {
        ValidForFunction(*previous);
      } else if ((*current).IsBinaryOperator()) {
        ValidForBinOperator(*previous);
      } else if ((*current).IsCloseParenthesis()) {
        ValidForCloseParenthesis(*previous);
        ++count_close_parenthesis;
      } else if ((*current).IsOpenParenthesis()) {
        ValidForOpenParenthesis(*previous);
        ++count_open_parenthesis;
      }
      ++current;
      ++previous;
    }
    if (ValidForLast(tokens.back()) &&
        this->AdditionalCheckForBrackets(count_close_parenthesis,
                                         count_open_parenthesis)) {
      if (count_open_parenthesis > count_close_parenthesis) {
        while (count_open_parenthesis != count_close_parenthesis) {
          tokens.push_back(Token(Token::TypeTokens::kCloseParenthesis, ")", 0));
          ++count_close_parenthesis;
        }
      }
    }
  }
}

bool Validator::ValidForFirst(const Token& current) {
  if (current.IsUnaryOperator() || current.IsFunction() || current.IsNumber() ||
      current.IsOpenParenthesis()) {
    return true;
  } else {
    throw std::logic_error("Invalid value at the beginning of an expression");
  }
  return false;
}

void Validator::ValidForNumber(const Token& previous) {
  if (!(previous.IsBinaryOperator() || previous.IsUnaryOperator() ||
        previous.IsOpenParenthesis())) {
    throw std::logic_error("Incorrect position for number");
  }
}

void Validator::ValidForFunction(const Token& previous) {
  if (!(previous.IsBinaryOperator() || previous.IsOpenParenthesis() ||
        previous.IsUnaryOperator())) {
    throw std::logic_error("Incorrect position for function");
  }
}

void Validator::ValidForOpenParenthesis(const Token& previous) {
  if (!(previous.IsFunction() || previous.IsBinaryOperator() ||
        previous.IsOpenParenthesis() || previous.IsUnaryOperator())) {
    throw std::logic_error("Inncorect position for open parenthesis");
  }
}

void Validator::ValidForCloseParenthesis(const Token& previous) {
  if (!(previous.IsNumber() || previous.IsCloseParenthesis())) {
    throw std::logic_error("Inncorect position for close parenthesis");
  }
}

void Validator::ValidForBinOperator(const Token& previous) {
  if (!(previous.IsNumber() || previous.IsCloseParenthesis())) {
    throw std::logic_error("Incorrect position for binary operator");
  }
}

bool Validator::ValidForLast(const Token& current) {
  if (current.IsBinaryOperator() || current.IsOpenParenthesis() ||
      current.IsFunction() || current.IsUnaryOperator()) {
    throw std::logic_error("The last symbol is wrong");
  }
  return true;
}

bool Validator::AdditionalCheckForBrackets(const int& close, const int& open) {
  if (close > open) {
    throw std::logic_error("Closing brackets must be exactly");
  }
  return true;
}

}  // namespace s21
