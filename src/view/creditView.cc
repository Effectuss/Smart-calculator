#include "creditView.h"
#include "ui_creditView.h"

namespace s21 {
CreditView::CreditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditView)
{
    ui->setupUi(this);
}

void CreditView::SetController(Controller *controller)
{
    this->controller_ = controller;
}

void CreditView::InitWindow()
{

}

CreditView::~CreditView()
{
    delete ui;
}

void CreditView::closeEvent(QCloseEvent *event)
{
    emit showParent();
    this->hide();
}
}
