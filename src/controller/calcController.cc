#include "calcController.h"

namespace s21 {
double CalcController::CalculateMath(std::string& str_from_label, double& x) {
  return model_->GetResultExpression(str_from_label, x);
}

}  // namespace s21
