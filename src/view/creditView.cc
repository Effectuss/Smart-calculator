#include "creditView.h"
#include "ui_creditView.h"

namespace s21 {
CreditView::CreditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditView)
{
    ui->setupUi(this);
    connect(ui->actionCalculate, SIGNAL(clicked()), SLOT(OnActionCalculateClicked()));
    connect(ui->actionClose, SIGNAL(clicked()), SLOT(OnActionCloseClicked()));
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

void CreditView::SetController(Controller *controller)
{
    this->controller_ = controller;
}

void CreditView::InitWindow()
{

}

void CreditView::OnActionCalculateClicked()
{
    qDebug() << "HELLO";
}

void CreditView::OnActionCloseClicked()
{
    qDebug() << "BB";

}

}
