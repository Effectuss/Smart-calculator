#include "calcView.h"
#include "./ui_calcView.h"

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

