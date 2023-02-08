#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "token.h"

namespace s21 {

class CalcModel {
 public:

  void ToTokens(std::string& expression, double& x);
  bool TokenizationNumber();
  bool TokenizationX();
  bool TokenizationOperator();
  bool TokenizationFunction();
  bool TokenizationOpenParen();
  bool TokenizationCloseParen();


  void Validation();
  std::string& ComputeExpressin(std::string& intput_str, double& x);

  void PrintTokens() {
    auto count = 1;
    for (auto el : this->l_tokens_) {
      std::cout << count << ". TOKEN: " << el.GetTokenString()
                << ", PRIORITY: " << el.GetPriority() << std::endl;
    }
  }

 private:
  std::string output_result_;
  std::list<Token> l_tokens_;
  std::vector<std::string> function_ = {"sin",  "cos",  "tan",  "log", "ln",
                                        "acos", "asin", "atan", "sqrt"};
};
}  // namespace s21

#endif  // __CALCMODEL_H__
