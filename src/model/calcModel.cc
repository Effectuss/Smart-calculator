#include "calcModel.h"

namespace s21 {
std::string CalcModel::GetInputStr() const { return input_str_; }

void CalcModel::SetInputStr(std::string& input_str) {
  this->input_str_ = input_str;
}

}  // namespace s21