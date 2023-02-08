#include "calcModel.h"

int main() {
  std::string str = "-3+3-(-2)*sin(33)";
  s21::CalcModel model;
  double x = .6e0;
  std::cout << x << std::endl;
  try {
    model.ToTokens(str, x);
    model.PrintTokens();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}