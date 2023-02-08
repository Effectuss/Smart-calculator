#include "calcController.h"

namespace s21 {
std::string CalcController::Calculate(std::string& str_from_label, double& x) {
  std::string test_ = "Incorect input";
  try {
    model_->ToTokens(str_from_label, x);
    model_->Validation();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return test_;
}

}  // namespace s21
