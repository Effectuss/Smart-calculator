#include "calcController.h"

namespace s21 {
std::string& CalcController::Calculate(std::string& str_from_label) {
  std::string test_ = "Incorect input";
  model_->SetInputStr(test_);
  return model_->GetInputStr();
}

}  // namespace s21
