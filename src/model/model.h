#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include "./credit/creditCalc.h"
#include "./math/mathCalc.h"

class Model {
 public:
  Model() {}
  explicit Model(const MathCalc& math_calc_, const CreditCalc& credit_calc)
      : math_calc_{math_calc_}, credit_calc_{credit_calc} {}

  double GetResultMathExpression(std::string& str_from_label, const double& x) {
    return this->math_calc_.ShuntingYard(str_from_label, x);
  }
  CreditCalc& GetCreditCalc() { return this->credit_calc_; }

 private:
  MathCalc math_calc_;
  CreditCalc credit_calc_;
};


#endif  // __CALCMODEL_H__
