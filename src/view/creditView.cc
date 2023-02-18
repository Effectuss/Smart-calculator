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
    connect(ui->actionClear, SIGNAL(clicked()), SLOT(OnActionClearClicked()));
}

CreditView::~CreditView()
{
    delete ui;
}

void CreditView::closeEvent(QCloseEvent *event)
{
    this->OnActionCloseClicked();
}

void CreditView::SetController(Controller *controller)
{
    this->controller_ = controller;
}

void CreditView::FillDataForCount(CreditCalc::DataForCredit& data_for_credit)
{
    data_for_credit.sum_credit = ui->valueAmountOfCredit->value();
    data_for_credit.amount_month = ui->valueMonthTerm->value();
    data_for_credit.interest_rate = ui->valueInterestRate->value();
    if(ui->setAnnuity->isChecked()) {
        data_for_credit.type_credit = CreditCalc::TypeOfCredit::kAnnuity;
    } else {
        data_for_credit.type_credit = CreditCalc::TypeOfCredit::kDifferentiated;
    }
}

void CreditView::SetDefaultSettings()
{
    ui->valueAmountOfCredit->setValue(ui->valueAmountOfCredit->minimum());
    ui->valueInterestRate->setValue(ui->valueInterestRate->minimum());
    ui->valueMonthTerm->setValue(ui->valueMonthTerm->minimum());
    ui->tableForCredit->clearContents();
}

void CreditView::OnActionCalculateClicked()
{
    ui->tableForCredit->clearContents();
    CreditCalc::DataForCredit data_for_credit;
    FillDataForCount(data_for_credit);
    this->controller_->CalculateDataForCredit(data_for_credit);
}

void CreditView::OnActionCloseClicked()
{
    emit showParent();
    this->close();
}

void CreditView::OnActionClearClicked()
{
    this->SetDefaultSettings();
}

}
