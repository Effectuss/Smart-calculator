#include "calcModel.h"

namespace s21 {

double CalcModel::GetResultMathExpression(std::string& str_from_label,
                                          double& x) {
  // auto aboba = kFunctions.at("sin")(5);
  return this->math_calc_.ShuntingYard(str_from_label, x);
}

}  // namespace s21
