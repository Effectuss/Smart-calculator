#include "calcController.h"

namespace s21 {
std::string CalcController::Calculate(std::string& str_from_label, double &x) {
  std::string test_ = "Incorect input";
    model_->ShuntingYard(str_from_label, x);
  return model_->GetInputStr();
}

}  // namespace s21
