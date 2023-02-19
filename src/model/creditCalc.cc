#include "creditCalc.h"

#include <QDebug>

#include "iostream"
namespace s21 {

void CreditCalc::CalculateCredit(DataForCredit &data_for_credit) {
  if (data_for_credit.type_credit == CreditCalc::TypeOfCredit::kAnnuity) {
    this->AnnuityCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table);

    data_for_credit.money_for_bank =
        (this->pay_per_month_ * data_for_credit.amount_month) -
        data_for_credit.sum_credit;
    data_for_credit.all_money =
        data_for_credit.sum_credit + data_for_credit.money_for_bank;

  } else if (data_for_credit.type_credit ==
             CreditCalc::TypeOfCredit::kDifferentiated) {
    this->DifferentiatedCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table);
  }
}

void CreditCalc::AnnuityCredit(
    double &sum_credit, double amount_months, double &interest_rate,
    std::vector<std::array<double, 4>> data_for_table) {
  this->interest_per_month_ = interest_rate / (100.0L * 12.0L);
  this->pay_per_month_ =
      sum_credit *
      ((interest_rate / 100.0L / 12.0L) +
       ((interest_rate / 100.0L / 12.0L) /
        (pow(1.0L + (interest_rate / 100.0L / 12.0L), amount_months) - 1.0L)));
  this->after_payment_ = sum_credit;

  for (int i = 0; i < static_cast<int>(amount_months); --amount_months) {
    this->pay_by_interest_ = this->after_payment_ * this->interest_per_month_;

    this->pay_by_main_duty_ = this->pay_per_month_ - this->pay_by_interest_;

    this->after_payment_ -= this->pay_by_main_duty_;

    data_for_table.push_back({this->pay_per_month_, this->pay_by_main_duty_,
                              this->pay_by_interest_, this->after_payment_});
  }
}

void CreditCalc::DifferentiatedCredit(
    double &sum_credit, double amount_months, double &interest_rate,
    std::vector<std::array<double, 4>> data_for_table) {
  //  for (const auto &it : data_for_table) {
  //    for (auto i = 0; i < it.size(); ++i) {
  //      std::cout << it.at(i) << " ";
  //    }
  //    std::cout << std::endl;
  //  }
}

}  // namespace s21
