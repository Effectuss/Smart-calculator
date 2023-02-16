#include <QApplication>

#include "calcView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  s21::CalcView window_main;
  s21::GraphView graph;
  graph.SetController(&controller);
  window_main.SetController(&controller);
  window_main.show();
  return a.exec();
}
