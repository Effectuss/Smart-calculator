#include "mathCalc.h"

namespace s21 {
Tokenizator& MathCalc::GetTokenizator() { return this->tokenizator_; }

Validator& MathCalc::GetValidator() { return this->validator_; }

double MathCalc::ShuntingYard(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());
  return 0.0;
}

}  // namespace s21