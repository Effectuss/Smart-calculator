#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../model/calcModel.h"

TEST(MathCalculator, expression1) {
  std::string check_str = "3mod4*(-3*sin(4)-cos(0.3))";
  s21::CalcModel model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (fmod(3.0, 4.0) * ((-3.0 * (sin(4.0))) - (cos(0.3))));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
