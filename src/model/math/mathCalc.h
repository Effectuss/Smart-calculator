#ifndef __MATHCALC_H__
#define __MATHCALC_H__
#include <cmath>
#include <functional>
#include <list>
#include <map>
#include <stack>
#include <string>

#include "tokenizator.h"
#include "validator.h"

namespace s21 {
class MathCalc {
 public:
  double ShuntingYard(std::string& str_from_label, const double& x);
  static void CountValue(std::stack<Token>& stack_operations,
                         std::stack<double>& stack_number);

 private:
  static const std::map<std::string, std::function<double(double)>> kFunctions_;
  static const std::map<std::string, std::function<double(double, double)>>
      kOperators_;
  Tokenizator tokenizator_;
  Validator validator_;
};

}  // namespace s21

#endif  // __MATHCALC_H__
