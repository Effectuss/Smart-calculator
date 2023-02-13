#include "mathCalc.h"

namespace s21 {

inline const std::map<std::string, std::function<double(double)>>
    MathCalc::kFunctions{{"sin", [](double x) -> double { return sin(x); }},
                         {"cos", [](double x) -> double { return cos(x); }},
                         {"tan", [](double x) -> double { return tan(x); }},
                         {"acos", [](double x) -> double { return acos(x); }},
                         {"asin", [](double x) -> double { return asin(x); }},
                         {"atan", [](double x) -> double { return atan(x); }},
                         {"sqrt", [](double x) -> double { return sqrt(x); }},
                         {"ln", [](double x) -> double { return log(x); }},
                         {"log", [](double x) -> double { return log10(x); }}};

double MathCalc::ShuntingYard(std::string& str_from_label, double& x) {
  this->tokenizator_.ToTokens(str_from_label, x);
  this->validator_.Validation(this->tokenizator_.GetListToken());
  std::stack<double> stack_number;
  std::stack<std::string> stack_operators;

  return 0.0;
}

}  // namespace s21