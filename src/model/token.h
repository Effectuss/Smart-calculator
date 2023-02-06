#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <map>
#include <string>

// left or right
// if rignt then binary
class Token {
 public:
  enum class TypeTokens {
    NUMBER = 1,
    BINARY_OPERATOR,
    UNARY_OPERATOR,
    FUNCTION
  };
  Token();
  Token(const short& type, const std::string& token, short priority);
  short GetPriority();
  void FillPriority(const short& priority);
  bool IsFunction();
  bool IsNumber();
  bool IsBinaryOperator();
  bool IsUnaryOperator();

 private:
  std::map<short, std::string> type_and_token_;
  short priority_;
};

#endif  // __TOKEN_H__