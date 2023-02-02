#ifndef __CALCMODEL_H__
#define __CALCMODEL_H__

#include <cmath>
#include <iostream>
#include <string>

namespace s21 {

typedef struct Token {
  
} Token;

class CalcModel {
 public:
  CalcModel() {}
  std::string GetInputStr() const;
  void SetInputStr(std::string& input_str);

 private:
  std::string input_str_;
};
}  // namespace s21

#endif  // __CALCMODEL_H__
