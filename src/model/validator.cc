#include "validator.h"

namespace s21 {
void Validator::Validation(std::list<Token>& tokens) {
  if (Validator::ValidForFirst(tokens.front())) {
    auto current = tokens.begin();
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
        this->count_close_parenthesis++;
      } else if ((*current).IsOpenParenthesis()) {
        ValidForOpenParenthesis(*previous);
        this->count_open_parenthesis++;
      } else if ((*current).IsUnaryOperator()) {
        ValidForUnaryOperator(*previous);
      }
      ++current;
      ++previous;
    }
    if (ValidForLast(tokens.back())) {
      if (this->count_close_parenthesis < this->count_open_parenthesis) {
      }
    }
  }
}

bool Validator::ValidForFirst(const Token& current) {
  if (current.IsUnaryOperator() || current.IsFunction() || current.IsNumber()) {
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
  if (!(previous.IsBinaryOperator() || previous.IsOpenParenthesis())) {
    throw std::logic_error("Incorrect position for function");
  }
}

void Validator::ValidForOpenParenthesis(const Token& previous) {
  if (!(previous.IsFunction() || previous.IsBinaryOperator() ||
        previous.IsOpenParenthesis())) {
    throw std::logic_error("Inncorect position for open parenthesis");
  }
}

void Validator::ValidForCloseParenthesis(const Token& previous) {
  if (!(previous.IsNumber())) {
    throw std::logic_error("Inncorect position for close parenthesis");
  }
}

void Validator::ValidForBinOperator(const Token& previous) {
  if (!(previous.IsNumber() || previous.IsCloseParenthesis() ||
        previous.IsOpenParenthesis())) {
    throw std::logic_error("Incorrect position for binary operator");
  }
}

void Validator::ValidForUnaryOperator(const Token& previous) {
  if (!(previous.IsOpenParenthesis())) {
    throw std::logic_error("Incorrect position for unary operator");
  }
}

bool Validator::ValidForLast(const Token& current) {
  if (current.IsBinaryOperator() || current.IsOpenParenthesis()) {
    throw std::logic_error("The last symbol is wrong");
  }
  return true;
}

}  // namespace s21