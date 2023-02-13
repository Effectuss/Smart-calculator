#include "calcModel.h"
// std::array<int, 5> ab;
// std::arrat<int> dsad;
// ab = dsad;

int main() {
  std::string str = "9-3+sin(33)";
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
