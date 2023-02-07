#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <map>
#include <string>

namespace s21 {
class Token {
 public:
  enum class TypeTokens {
    NUMBER = 1,
    BINARY_OPERATOR,
    UNARY_OPERATOR,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    FUNCTION
  };

  Token(const TypeTokens& type, const std::string& token, short priority = -1);
  short GetPriority() const { return priority_; }
  std::string GetTokenString() const { return type_and_token_.second; }
  void FillPriority(const short& priority);

 private:
  std::pair<TypeTokens, std::string> type_and_token_;
  short priority_;
};
}  // namespace s21

#endif  // __TOKEN_H__