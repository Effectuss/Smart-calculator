#include "calcModel.h"

namespace s21 {

double CalcModel::GetResultExpression(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  
  return 33.3;
}

Tokenizator& CalcModel::GetTokenizator() { return this->tokenizator_; }

}  // namespace s21
