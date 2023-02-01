#include "calcView.h"

#include "ui_calcView.h"

namespace s21 {
CalcView::CalcView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalcView) {
  ui->setupUi(this);
}

void CalcView::SetController(CalcController *controller) {
  this->controller_ = controller;
}

CalcView::~CalcView() { delete ui; }
}  // namespace s21
