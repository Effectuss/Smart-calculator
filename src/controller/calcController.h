#ifndef __CALCCONTROLLER_H__
#define __CALCCONTROLLER_H__

#include "../model/calcModel.h"

namespace s21 {
class CalcController {
 public:
  CalcController(CalcModel *model) : model_{model} {};
  std::string Calculate(std::string &str_from_label, double&x);

 private:
  CalcModel *model_;
};
}  // namespace s21

#endif  // __CALCCONTROLLER_H__
