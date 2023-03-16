#ifndef __TOKENIZATOR_H__
#define __TOKENIZATOR_H__

#include <algorithm>

#include "token.h"

class Tokenizator {
public:
  void ToTokens(std::string &expression, const double &x);
  bool TokenizationNumber(std::string &expression, std::size_t &i);
  bool TokenizationX(const std::string &expression, const double &x,
                     const std::size_t &i);
  bool TokenizationOperator(std::string &expression, std::size_t &i);
  bool TokenizationFunction(std::string &expression, std::size_t &i);
  bool TokenizationOpenParen(const std::string &expression, std::size_t &i);
  bool TokenizationCloseParen(const std::string &expression, std::size_t &i);

  static bool IsCorrectFunction(const std::string &expression,
                                const std::vector<std::string> &function);
  static bool IsCorrectNumber(const std::string &number);

  static bool IsFunction(const char &symb);
  static bool IsOperator(const char &symb);

  std::list<Token> &GetListToken();

private:
  std::list<Token> l_tokens_;
  static const std::vector<std::string> kFunction_;
};

inline const std::vector<std::string> Tokenizator::kFunction_{
    "sin", "cos", "tan", "log", "ln", "acos", "asin", "atan", "sqrt"};

#endif // __TOKENIZATOR_H__
