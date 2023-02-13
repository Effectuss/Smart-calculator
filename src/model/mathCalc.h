#ifndef __MATHCALC_H__
#define __MATHCALC_H__
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "tokenizator.h"
#include "validator.h"

namespace s21 {
class MathCalc {
 public:
  double ShuntingYard(std::string& str_from_label, double& x);
  Tokenizator& GetTokenizator();
  Validator& GetValidator();

 private:
  static const std::map<std::string, double (*)(double)> kFunctions;
  Tokenizator tokenizator_;
  Validator validator_;
};

inline const std::map<std::string, double (*)(double)> MathCalc::kFunctions{
    {"sin", [](double x) -> double { return sin(x); }}};
}  // namespace s21

#endif  // __MATHCALC_H__