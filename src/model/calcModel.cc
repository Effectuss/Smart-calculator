#include "calcModel.h"

namespace s21 {

double CalcModel::GetResultExpression(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());
  return 33.3;
}

Tokenizator& CalcModel::GetTokenizator() { return this->tokenizator_; }

Validator& CalcModel::GetValidator() { return this->validator_; }

}  // namespace s21
