#include <QApplication>

#include "calcView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CreditCalc credit_calc;
  s21::MathCalc math_calc;
  s21::Model model(math_calc, credit_calc);
  s21::Controller controller(&model);
  s21::CalcView window_main;
  window_main.SetController(&controller);
  window_main.show();
  return a.exec();
}
