#include "smartcalc.h"
#include "./ui_smartcalc.h"

CalcView::CalcView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalcView)
{
    ui->setupUi(this);
}

CalcView::~CalcView()
{
    delete ui;
}

