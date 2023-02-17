#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include "mathCalc.h"
#include <QDebug>

namespace s21 {

class Model {
 public:
  double GetResultMathExpression(std::string& str_from_label, double& x) {
    return this->math_calc_.ShuntingYard(str_from_label, x);
  }

  MathCalc& GetMathCalc() { return this->math_calc_; }
  void PrintASD() { qDebug() << "ABOBA";}

 private:
  MathCalc math_calc_;
};

}  // namespace s21

#endif  // __CALCMODEL_H__
