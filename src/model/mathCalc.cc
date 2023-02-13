#include "mathCalc.h"

namespace s21 {

inline const std::map<std::string, double (*)(double)> MathCalc::kFunctions{
    {"sin", [](double x) -> double { return sin(x); }}};

double MathCalc::ShuntingYard(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());

  return 0.0;
}

}  // namespace s21