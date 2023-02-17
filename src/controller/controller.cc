#include "controller.h"

namespace s21 {
double Controller::CalculateMath(std::string& str_from_label, double& x) {
    return this->model_->GetResultMathExpression(str_from_label, x);
}

}  // namespace s21
