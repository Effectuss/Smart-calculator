#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include <vector>

namespace s21 {
class Token {
 public:
  enum class TypeTokens {
    NUMBER = 1,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    BINARY_OPERATOR,
    UNARY_OPERATOR,
    FUNCTION
  };

  Token(const TypeTokens& type, const std::string& token,
        const short& priority = -1);

  short GetPriority() const;
  std::string GetTokenString() const;
  TypeTokens GetType() const;

  bool IsNumber() const;
  bool IsFunction() const;
  bool IsOpenParenthesis() const;
  bool IsCloseParenthesis() const;
  bool IsBinaryOperator() const;
  bool IsUnaryOperator() const;

 private:
  std::pair<TypeTokens, std::string> type_and_token_;
  short priority_;
};
}  // namespace s21

#endif  // __TOKEN_H__