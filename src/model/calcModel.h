#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "token.h"
#include "tokenizator.h"
#include "validator.h"

namespace s21 {

class CalcModel {
 public:
  double GetResultExpression(std::string& str_from_label, double& x);
  Tokenizator& GetTokenizator();
  Validator& GetValidator();

  // void Validation();
  // std::string& ComputeExpressin(std::string& intput_str, double& x);

 private:
  Tokenizator tokenizator_;
  Validator validator_;
  std::vector<std::string> function_ = {"sin",  "cos",  "tan",  "log", "ln",
                                        "acos", "asin", "atan", "sqrt"};
};
}  // namespace s21

#endif  // __CALCMODEL_H__
