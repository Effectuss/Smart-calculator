#include "calcController.h"

namespace s21 {
std::string CalcController::Calculate(std::string &str_from_label) {
  model_->SetInputStr("Aboba");
  return model_->GetInputStr();
}

}  // namespace s21
