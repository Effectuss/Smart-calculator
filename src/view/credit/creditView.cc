#include "creditView.h"

#include "ui_creditView.h"

CreditView::CreditView(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditView) {
  ui->setupUi(this);
  connect(ui->actionCalculate, SIGNAL(clicked()),
          SLOT(OnActionCalculateClicked()));
  connect(ui->actionClose, SIGNAL(clicked()), SLOT(OnActionCloseClicked()));
  connect(ui->actionClear, SIGNAL(clicked()), SLOT(OnActionClearClicked()));
  ui->frameData->hide();
}

CreditView::~CreditView() { delete ui; }

void CreditView::closeEvent(QCloseEvent *event) {
  this->OnActionCloseClicked();
}

void CreditView::SetController(Controller *controller) {
  this->controller_ = controller;
}

void CreditView::FillDataForCount(CreditCalc::DataForCredit &data_for_credit) {
  data_for_credit.sum_credit = ui->valueAmountOfCredit->value();
  data_for_credit.amount_month = ui->valueMonthTerm->value();
  data_for_credit.interest_rate = ui->valueInterestRate->value();
  if (ui->setAnnuity->isChecked()) {
    data_for_credit.type_credit = CreditCalc::TypeOfCredit::kAnnuity;
  } else {
    data_for_credit.type_credit = CreditCalc::TypeOfCredit::kDifferentiated;
  }
}

void CreditView::SetDefaultSettings() {
  ui->valueAmountOfCredit->setValue(ui->valueAmountOfCredit->minimum());
  ui->valueInterestRate->setValue(ui->valueInterestRate->minimum());
  ui->valueMonthTerm->setValue(ui->valueMonthTerm->minimum());
  ui->tableForCredit->clearContents();
  ui->tableForCredit->setRowCount(0);
  ui->fillDebtInterest->clear();
  ui->fillInterestCharges->clear();
  ui->frameData->hide();
}

void CreditView::FillTheTable(CreditCalc::DataForCredit &data_for_credit) {
  ui->tableForCredit->setRowCount(data_for_credit.amount_month);
  for (auto row = 0; row < static_cast<int>(data_for_credit.amount_month);
       ++row) {
    for (auto column = 0; column < data_for_credit.data_for_table.at(0).size();
         ++column) {
      QString data = QString::number(
          data_for_credit.data_for_table.at(row).at(column), 'f', 2);
      QTableWidgetItem *item = new QTableWidgetItem(data);
      ui->tableForCredit->setItem(row, column, item);
    }
  }
  ui->fillDebtInterest->setText(
      QString::number(data_for_credit.all_money, 'f', 2));
  ui->fillInterestCharges->setText(
      QString::number(data_for_credit.money_for_bank, 'f', 2));
  ui->frameData->show();
}

void CreditView::OnActionCalculateClicked() {
  ui->tableForCredit->clearContents();
  CreditCalc::DataForCredit data_for_credit;
  FillDataForCount(data_for_credit);
  this->controller_->CalculateDataForCredit(data_for_credit);
  this->FillTheTable(data_for_credit);
}

void CreditView::OnActionCloseClicked() {
  this->SetDefaultSettings();
  emit showParent();
  this->close();
}

void CreditView::OnActionClearClicked() { this->SetDefaultSettings(); }
