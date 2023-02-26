#include <gtest/gtest.h>

#include "../model/model.h"

TEST(MathCalculator, expression1) {
  std::string check_str = "3 mod4*(-3.0*sin(4)-cos(0.3))";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (fmod(3.0, 4.0) * ((-3.0 * (sin(4.0))) - (cos(0.3))));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression2) {
  std::string check_str = "-3*3/3-(-cos(-0.31+0.32)*sqrt(4))+3";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (-3.0) * 3.0 / 3.0 - ((-1.0 * cos(-0.31 + 0.32)) * sqrt(4.0)) + 3;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression3) {
  std::string check_str = "-ln(3)*acos(-0.32+0.1)*2.31/2+log(4)-(-1.3)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (((((-1.0) * log(3.0)) * acos(-0.32 + 0.1)) * 2.31 / 2.0) + log10(4.0)) -
      (-1.3);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression4) {
  std::string check_str = "10-(-928-16.6-438)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = 10 - (-928 - 16.6 - 438);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression5) {
  std::string check_str = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (3879294 - 5309583) - (3744311 - 2467480 - 4787696) - 3324295;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression6) {
  std::string check_str =
      "-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      -(-356.081 * 4598.63) * 803.928 * (70.592 * -.1569) * -36.1566;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression7) {
  std::string check_str = "(432/9.57/321)/(76.4/78.0)/(-35.8)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression8) {
  std::string check_str = "(7068./33.59/9.13-4)/43.5";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = (7068. / 33.59 / 9.13 - 4) / 43.5;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression9) {
  std::string check_str = "(45.34mod55.23)mod79.4";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = fmod(fmod(45.34, 55.23), 79.4);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression10) {
  std::string check_str = "357.34mod(952.34mod712.12)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = fmod(357.34, fmod(952.34, 712.12));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression11) {
  std::string check_str = "-(72*533+(-615))";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = -(72 * 533 + -615);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression12) {
  std::string check_str = "357.34mod(952.34mod712.12)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = fmod(357.34, fmod(952.34, 712.12));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression13) {
  std::string check_str = "-(72*533+(-615))";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = -(72 * 533 + -615);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression14) {
  std::string check_str = "(944mod918)/227+32-(-24)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = (fmod(944, 918)) / 227 + 32 - (-24);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression15) {
  std::string check_str = "cos(0)+tan(+2.0)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = cos(0) + tan(+2.0);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression16) {
  std::string check_str = "-(asin (+0.3465346)/2)+(atan(1.302+0.5)-1.2)";
  s21::Model model;
  double x = 0.0;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      -(asin(+0.3465346) / 2) + (atan(1.302 + 0.5) - 1.2);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression17) {
  std::string check_str = "xmodsqrt(100)/ln(256-3)*log(+123.345)";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (fmod(x, sqrt(100))) / log(256 - 3) * log10(+123.345);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression18) {
  std::string check_str = "-sin(13.4+atan(7)*56.4-17/4)*(cos(tan(x^4)))";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      -sin(13.4 + atan(7) * 56.4 - 17 / 4.0) * (cos(tan(pow(x, 4))));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression19) {
  std::string check_str =
      "cos(0.33*0.42)+(sin(1)-1.3)-tan(1.3)*acos(0.2)+asin(0.1)+sqrt(4)-ln("
      "120)+log(x)";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = cos(0.33 * 0.42) + (sin(1) - 1.3) -
                              tan(1.3) * acos(0.2) + asin(0.1) + sqrt(4) -
                              log(120) + log10(x);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression20) {
  std::string check_str = "-(-0.33)-(-0.21+(+32.1))-(-0.1+93)*11/23.3";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      -(-0.33) - ((-0.21) + 32.1) - (-0.1 + 93) * 11 / 23.3;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression21) {
  std::string check_str = "-sin(-x)*cos(x)-x+(+x)-(-x)*(-sin(-x))";
  s21::Model model;
  double x = 0.32;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      sin(0.32) * cos(0.32) - 0.32 + 0.32 - ((-0.32) * (-sin(-0.32)));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression22) {
  std::string check_str =
      "-sqrt(-x)+acos(x)*asin(-0.1-(-x))*atan(-x)+log(x+2.3)/tan(x)-(-x)";
  s21::Model model;
  double x = -0.31;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      (((-sqrt(-(-0.31))) +
        (acos(-0.31) * asin(-0.1 - (-(-0.31))) * atan(-(-0.31))))) +
      (log10((-0.31) + 2.3) / tan(-0.31)) - (-(-0.31));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression23) {
  std::string check_str = "-33.9-(-3.1)-(-2.3)-(-(-32.1";
  s21::Model model;
  double x = -0.31;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = -33.9 - (-3.1) - (-2.3) - (-(-32.1));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression24) {
  std::string check_str =
      "cos(0.33e-10*0.42e2)+(sin(1)-1.3)-tan(1.3e1)*acos(0.2)+asin(0.1)+sqrt("
      "4e11)-ln("
      "120)+log(x)";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = cos(0.33e-10 * 0.42e2) + (sin(1) - 1.3) -
                              tan(1.3e1) * acos(0.2) + asin(0.1) + sqrt(4e11) -
                              log(120) + log10(x);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression25) {
  std::string check_str = "2*2^3^2+43.33*2/2/33";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = (2 * (pow(2, pow(3, 2)))) + 43.33 * 2 / 2 / 33;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression26) {
  std::string check_str = "2^3^2^sin(5)";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = pow(2, pow(3, pow(2, sin(5))));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression27) {
  std::string check_str = "x^sin(33)^sin(23)^3";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = pow(x, (pow(sin(33), pow(sin(23), 3))));
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression28) {
  std::string check_str =
      "x^sin(33)^sin(23)^3^33*sin(2)*sqrt(33)-22+(-123.3232)";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus =
      pow(x, (pow(sin(33), pow(sin(23), pow(3, 33))))) * sin(2) * sqrt(33) -
      22 + (-123.3232);
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression29) {
  std::string check_str =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = -30.072164948453608;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(MathCalculator, expression30) {
  std::string check_str = "1+3";
  s21::Model model;
  double x = 33.33;
  double result = model.GetResultMathExpression(check_str, x);
  double result_c_plus_plus = 1 + 3;
  ASSERT_DOUBLE_EQ(result, result_c_plus_plus);
}

TEST(ExeptionrTest, exeption1) {
  try {
    std::string input_str = "3---4***23";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
  } catch (const std::exception& exp) {
    std::string exeption_str =
        "Binary operators cannot be repeated or unknown operator";
    EXPECT_STREQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption2) {
  try {
    std::string input_str = "3mo4*3";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str =
        "Binary operators cannot be repeated or unknown operator";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption3) {
  try {
    std::string input_str = "si(33)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Name of available functions is incorrect";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption4) {
  try {
    std::string input_str = "cos(33)+t(33)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Name of available functions is incorrect";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption5) {
  try {
    std::string input_str = "3e";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The number you entered is incorrect";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption6) {
  try {
    std::string input_str = "3-3e";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The number you entered is incorrect";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption7) {
  try {
    std::string input_str = ")sin(33+33)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str =
        "Invalid value at the beginning of an expression";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption8) {
  try {
    std::string input_str = "^33-23";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str =
        "Invalid value at the beginning of an expression";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption9) {
  try {
    std::string input_str = "sin33+42";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for number";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption10) {
  try {
    std::string input_str = "33)23";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for number";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption11) {
  try {
    std::string input_str = "sin(33)cos(23)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for function";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption12) {
  try {
    std::string input_str = "sin(33)+33)cos";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for function";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption13) {
  try {
    std::string input_str = "33(22";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Inncorect position for open parenthesis";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption14) {
  try {
    std::string input_str = "(33)(";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Inncorect position for open parenthesis";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption16) {
  try {
    std::string input_str = "(33+()";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Inncorect position for close parenthesis";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption17) {
  try {
    std::string input_str = "sin+33";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for binary operator";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption18) {
  try {
    std::string input_str = "(*33)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for binary operator";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption19) {
  try {
    std::string input_str = "(33)-(^33)*(/23)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Incorrect position for binary operator";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption20) {
  try {
    std::string input_str = "3+23^sin(32)+sin";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The last symbol is wrong";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption21) {
  try {
    std::string input_str = "-";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The last symbol is wrong";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption22) {
  try {
    std::string input_str = "33+23*(";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The last symbol is wrong";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption23) {
  try {
    std::string input_str = "33-23-";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "The last symbol is wrong";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption24) {
  try {
    std::string input_str = "42^33+23))))))";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    std::string exeption_str = "Closing brackets must be exactly";
    EXPECT_STRCASEEQ(exeption_str.c_str(), exp.what());
  }
}

TEST(ExeptionrTest, exeption25) {
  try {
    std::string input_str = "h32gti123wqkmbkl+33-x";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    SUCCEED();
  }
}

TEST(ExeptionrTest, exeption26) {
  try {
    std::string input_str = "  12 asd + sad dfkdd kogd(223)";
    s21::Model model;
    double x = 0.0;
    model.GetResultMathExpression(input_str, x);
    FAIL() << "Exception does not thrown";
  } catch (const std::exception& exp) {
    SUCCEED();
  }
}
