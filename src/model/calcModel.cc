#include "calcModel.h"

namespace s21 {
std::string CalcModel::GetInputStr() const { return output_result_; }

void CalcModel::SetInputStr(std::string &input_str) {
  this->output_result_ = input_str;
}

std::string& CalcModel::ShuntingYard(std::string &intput_str, double &x) {}

}  // namespace s21
