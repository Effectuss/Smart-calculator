#include "calcModel.h"

int main() {
  std::string str = "2+3*3/33";
  s21::CalcModel model;
  double x = 0.0;
  model.ShuntingYard(str, x);
  std::cout << str;
  return 0;
}