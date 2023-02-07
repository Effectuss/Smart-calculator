#include "token.h"
namespace s21 {
Token::Token(const TypeTokens& type, const std::string& token, short priority)
    : priority_{priority}{
  type_and_token_.first = type;
  type_and_token_.second = token;
}

}  // namespace s21