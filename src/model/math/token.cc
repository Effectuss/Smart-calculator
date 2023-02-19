#include "token.h"

namespace s21 {

Token::Token(const TypeTokens& type, const std::string& token,
             const short& priority)
    : priority_{priority} {
  type_and_token_.first = type;
  type_and_token_.second = token;
}

short Token::GetPriority() const { return priority_; }

std::string Token::GetTokenString() const { return type_and_token_.second; }

Token::TypeTokens Token::GetType() const { return type_and_token_.first; };

bool Token::IsNumber() const {
  return type_and_token_.first == TypeTokens::kNumber;
}

bool Token::IsFunction() const {
  return type_and_token_.first == TypeTokens::kFunction;
}

bool Token::IsOpenParenthesis() const {
  return type_and_token_.first == TypeTokens::kOpenParenthesis;
}

bool Token::IsCloseParenthesis() const {
  return type_and_token_.first == TypeTokens::kCloseParenthesis;
}

bool Token::IsBinaryOperator() const {
  return type_and_token_.first == TypeTokens::kBinaryOperator;
}

bool Token::IsUnaryOperator() const {
  return type_and_token_.first == TypeTokens::kUnaryOperator;
}

}  // namespace s21
