#ifndef __MATHCALC_H__
#define __MATHCALC_H__
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "tokenizator.h"
#include "validator.h"

namespace s21 {
class MathCalc {
 public:
  double ShuntingYard(std::string& str_from_label, double& x);
  Tokenizator& GetTokenizator() { return this->tokenizator_; }
  Validator& GetValidator() { return this->validator_; }

 private:
  static const std::map<std::string, std::function<double(double)>> kFunctions_;
  static const std::map<std::string, std::function<double(double, double)>>
      kOperators_;
  Tokenizator tokenizator_;
  Validator validator_;
};

}  // namespace s21

#endif  // __MATHCALC_H__