#include "calcModel.h"

int main() {
  std::string str = "33.3e----010*323^ln(32)";
  s21::CalcModel model;
  double x = .6e0;
  std::cout << x << std::endl;

  try {
    model.GetResultExpression(str, x);
    model.GetTokenizator().PrintTokens();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}