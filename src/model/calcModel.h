#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "token.h"

namespace s21 {

class CalcModel {
 public:
  CalcModel() {}
  std::string GetInputStr() const;
  void SetInputStr(std::string& input_str);
  std::string& ShuntingYard(std::string& intput_str, double& x);

 private:
  std::string output_result_;
  std::vector<Token> v_tokens_;
};
}  // namespace s21

#endif  // __CALCMODEL_H__
