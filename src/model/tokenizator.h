#ifndef __TOKENIZATOR_H__
#define __TOKENIZATOR_H__

#include <iostream>
#include <list>

#include "token.h"

namespace s21 {
class Tokenizator {
 public:
  void ToTokens(std::string& expression, double& x);
  bool TokenizationNumber(std::string& expression, int& i);
  bool TokenizationX(std::string& expression, double& x, int& i);
  bool TokenizationOperator(std::string& expression, int& i);
  bool TokenizationFunction(std::string& expression, int& i);
  bool TokenizationOpenParen(std::string& expression, int& i);
  bool TokenizationCloseParen(std::string& expression, int& i);

  static bool IsCorrectFunction(const std::string& expression,
                                const std::vector<std::string>& function);
  static bool IsCorrectNumber(const std::string& number);

  static bool IsFunction(const char& symb);
  static bool IsOperator(const char& symb);

  std::list<Token>& GetListToken();

  void PrintTokens() {
    auto count = 1;
    for (auto el : this->l_tokens_) {
      std::cout << count << ". TOKEN: " << el.GetTokenString()
                << ", PRIORITY: " << el.GetPriority() << std::endl;
    }
  }

 private:
  std::list<Token> l_tokens_;
  static const std::vector<std::string> kFunction_;
};

inline const std::vector<std::string> Tokenizator::kFunction_{
    "sin", "cos", "tan", "log", "ln", "acos", "asin", "atan", "sqrt"};

}  // namespace s21
#endif  // __TOKENIZATOR_H__