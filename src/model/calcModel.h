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
  CalcModel() {}
  std::string GetInputStr() const;
  void SetInputStr(std::string& input_str);
  bool IsFunction();
  void ToTokens(std::string& expression, double& x);

  void Validation();
  std::string& ComputeExpressin(std::string& intput_str, double& x);

  // tmp method
  void PrintTokens() {
    auto count = 1;
    for (auto el : this->v_tokens_) {
      std::cout << count << ". TOKEN: " << el.GetTokenString()
                << ", PRIORITY: " << el.GetPriority() << std::endl;
    }
  }

 private:
  std::string output_result_;
  std::list<Token> v_tokens_;
};
}  // namespace s21

#endif  // __CALCMODEL_H__
