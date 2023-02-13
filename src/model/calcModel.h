#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include "mathCalc.h"

namespace s21 {

class CalcModel {
 public:
  double GetResultMathExpression(std::string& str_from_label, double& x);
  MathCalc& GetMathCalc() { return this->math_calc_; }

 private:
  MathCalc math_calc_;
};

}  // namespace s21

#endif  // __CALCMODEL_H__
