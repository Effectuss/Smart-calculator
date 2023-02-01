#include "calcController.h"

namespace s21 {
std::string CalcController::Calculate() {
  model_->SetInputStr("Aboba");
  return model_->GetInputStr();
}

}  // namespace s21