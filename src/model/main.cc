#include "calcModel.h"
// std::array<int, 5> ab;
// std::arrat<int> dsad;
// ab = dsad;

int main() {
  std::string str = "asin(-9)";
  s21::CalcModel model;
  double x = 7.5;
  std::cout << x << std::endl;
  try {
    model.GetResultExpression(str, x);
    model.GetTokenizator().PrintTokens();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
