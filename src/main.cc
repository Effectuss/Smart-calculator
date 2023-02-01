#include <QApplication>

#include "./view/calcView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CalcModel model;
  s21::CalcController controller(&model);
  s21::CalcView w;
  w.SetController(&controller);
  w.show();
  return a.exec();
}
