#include "controller.h"

namespace s21 {
double Controller::CalculateMath(std::string& str_from_label, double& x) {
        qDebug() << "TI CHO";
    return this->model_->GetResultMathExpression(str_from_label, x);
}

void Controller::PrintZZZ()
{
    qDebug() << "CONTROLLER";
    this->model_->PrintASD();
}

}  // namespace s21
