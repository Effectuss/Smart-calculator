#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include <string>

namespace s21 {
class CalcModel {
 public:
  CalcModel() {}
  std::string GetInputStr();
  void SetInputStr(std::string input_str);

 private:
  std::string input_str_;
};
}  // namespace s21

#endif  // __CALCMODEL_H__
