#include "calcModel.h"
// std::array<int, 5> ab;
// std::arrat<int> dsad;
// ab = dsad;

int main() {
  std::string str = "sin((((((2+3";
  s21::CalcModel model;
  double x = 7.5;
  std::cout << x << std::endl;
  try {
    model.GetResultMathExpression(str, x);
    model.GetMathCalc().GetTokenizator().PrintTokens();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
