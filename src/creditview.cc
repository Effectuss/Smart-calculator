#include "creditview.h"
#include "ui_creditview.h"

CreditView::CreditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditView)
{
    ui->setupUi(this);
}

CreditView::~CreditView()
{
    delete ui;
}
