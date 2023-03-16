#include <QApplication>

#include "calcView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CreditCalc credit_calc;
  MathCalc math_calc;
  Model model(math_calc, credit_calc);
  Controller controller(&model);
  CalcView window_main;
  window_main.SetController(&controller);
  window_main.show();
  return a.exec();
}
