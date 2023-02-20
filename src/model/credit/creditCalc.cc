#include "creditCalc.h"

namespace s21 {

void CreditCalc::CalculateCredit(DataForCredit &data_for_credit) {
  if (data_for_credit.type_credit == CreditCalc::TypeOfCredit::kAnnuity) {
    this->AnnuityCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table);

    this->AnnuityAllMoneyAndBankMoney(data_for_credit);

  } else if (data_for_credit.type_credit ==
             CreditCalc::TypeOfCredit::kDifferentiated) {
    this->DifferentiatedCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table,
        data_for_credit.money_for_bank);

    this->DifferentiatedBankMoney(data_for_credit);
  }
}

void CreditCalc::AnnuityCredit(
    double &sum_credit, double amount_months, double &interest_rate,
    std::vector<std::array<double, 4>> &data_for_table) {
  this->interest_per_month_ = interest_rate / (100.0L * 12.0L);
  this->pay_per_month_ =
      sum_credit *
      ((interest_rate / 100.0L / 12.0L) +
       ((interest_rate / 100.0L / 12.0L) /
        (pow(1.0L + (interest_rate / 100.0L / 12.0L), amount_months) - 1.0L)));
  this->after_payment_ = sum_credit;

  for (int i = 0; i < static_cast<int>(amount_months); --amount_months) {
    this->pay_by_interest_ = this->after_payment_ * this->interest_per_month_;
    this->body_of_credit_ = this->pay_per_month_ - this->pay_by_interest_;
    this->after_payment_ -= this->body_of_credit_;
    data_for_table.push_back({this->pay_per_month_, this->body_of_credit_,
                              this->pay_by_interest_, this->after_payment_});
  }
}

void CreditCalc::DifferentiatedCredit(
    double &sum_credit, double amount_months, double &interest_rate,
    std::vector<std::array<double, 4>> &data_for_table,
    double &money_for_bank) {
  this->body_of_credit_ = sum_credit / amount_months;
  this->after_payment_ = sum_credit;
  const double average_day = 365.0L / 12.0L;
  interest_rate /= 100.0L;

  for (int i = 0; i < static_cast<int>(amount_months); ++i) {
    this->pay_by_interest_ =
        (this->after_payment_ * interest_rate * average_day) / 365.0L;
    this->pay_per_month_ = this->pay_by_interest_ + this->body_of_credit_;
    this->after_payment_ -= this->body_of_credit_;
    data_for_table.push_back({this->pay_per_month_, this->body_of_credit_,
                              this->pay_by_interest_, this->after_payment_});
    money_for_bank += this->pay_by_interest_;
  }
}

void CreditCalc::AnnuityAllMoneyAndBankMoney(DataForCredit &data_for_credit) {
  data_for_credit.money_for_bank =
      (this->pay_per_month_ * data_for_credit.amount_month) -
      data_for_credit.sum_credit;
  data_for_credit.all_money =
      data_for_credit.sum_credit + data_for_credit.money_for_bank;
}

void CreditCalc::DifferentiatedBankMoney(DataForCredit &data_for_credit) {
  data_for_credit.all_money =
      data_for_credit.sum_credit + data_for_credit.money_for_bank;
  data_for_credit.data_for_table
      .at(static_cast<int>(data_for_credit.amount_month) - 1)
      .at(3) = 0.0;
}
}  // namespace s21
