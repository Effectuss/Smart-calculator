#include "controller.h"

namespace s21 {
double Controller::CalculateMath(std::string& str_from_label, double& x) {
    return model_->GetResultMathExpression(str_from_label, x);
}

void Controller::FillVectors(QVector<double> &x_vector, QVector<double> &y_vector,std::string expression)
{
     model_->FillVectors(x_vector,y_vector,expression);
}

}  // namespace s21
