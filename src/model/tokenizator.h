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

  void PrintTokens() {
    auto count = 1;
    for (auto el : this->l_tokens_) {
      std::cout << count << ". TOKEN: " << el.GetTokenString()
                << ", PRIORITY: " << el.GetPriority() << std::endl;
    }
  }

 private:
  std::list<Token> l_tokens_;
};
}  // namespace s21
#endif  // __TOKENIZATOR_H__