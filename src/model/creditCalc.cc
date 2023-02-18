#include "creditCalc.h"

#include "iostream"

namespace s21 {

void CreditCalc::CalculateCredit(DataForCredit &data_for_credit) {
  if (data_for_credit.type_credit == CreditCalc::TypeOfCredit::kAnnuity) {
    this->AnnuityCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table);

  } else if (data_for_credit.type_credit ==
             CreditCalc::TypeOfCredit::kDifferentiated) {
    this->DifferentiatedCredit(
        data_for_credit.sum_credit, data_for_credit.amount_month,
        data_for_credit.interest_rate, data_for_credit.data_for_table);
  }
}

void CreditCalc::AnnuityCredit(
    long double &sum_credit, long double &amount_months,
    long double &interest_rate,
    std::vector<std::array<long double, 4>> data_for_table) {
  long double interest_per_month = interest_rate / (100.0L * 12.0L);
  long double pay_per_month =
      sum_credit *
      ((interest_rate / 100L / 12L) +
       ((interest_rate / 100L / 12L) /
        (pow(1L + (interest_rate / 100L / 12L), amount_months) - 1L)));

  long double after_payment = sum_credit;

  for (int i = 0; i < static_cast<int>(amount_months); --amount_months) {
    std::array<double, 4> tmp;
    data_for_table.at(i).push_back(tmp);
    data_for_table.at(i).at(NameOfColums::kPayPerMonth) = pay_per_month;
    data_for_table.at(i).at(NameOfColums::kInterestPay) =
        after_payment * interest_per_month;
    data_for_table.at(i).at(NameOfColums::kDebtPay) =
        pay_per_month - data_for_table.at(i).at(NameOfColums::kInterestPay);
    after_payment -= data_for_table.at(i).at(NameOfColums::kDebtPay);
    data_for_table.at(i).at(NameOfColums::kResidue) = after_payment;
  }
}

void CreditCalc::DifferentiatedCredit(
    long double &sum_credit, long double &amount_months,
    long double &interest_rate,
    std::vector<std::array<long double, 4>> data_for_table) {}

}  // namespace s21
