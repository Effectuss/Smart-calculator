#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

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

  Token(const TypeTokens& type, const std::string& token, short priority = -1)
      : priority_{priority} {
    type_and_token_.first = type;
    type_and_token_.second = token;
  }
  short GetPriority() const { return priority_; }
  std::string GetTokenString() const { return type_and_token_.second; }
  static bool IsFunction(const char& symb) {
    if (symb >= 'a' && symb <= 'z' && symb != 'm') return false;
    return true;
  };
  static bool IsOperator(const char& symb) {
    if (symb == '+' || symb == '-' || symb == '*' || symb == '/' ||
        symb == 'm' || symb == '^')
      return false;
    return true;
  }

 private:
  std::pair<TypeTokens, std::string> type_and_token_;
  short priority_;
};
}  // namespace s21

#endif  // __TOKEN_H__