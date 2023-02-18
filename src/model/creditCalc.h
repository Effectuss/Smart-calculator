#ifndef __CREDITCALC_H__
#define __CREDITCALC_H__
#include <array>
#include <cmath>
#include <vector>
namespace s21 {

class CreditCalc {
 public:
  enum TypeOfCredit { kAnnuity = 1, kDifferentiated };
  enum NameOfColums { kPayPerMonth, kDebtPay, kInterestPay, kResidue };

  struct DataForCredit {
    long double sum_credit;
    long double amount_month;
    long double interest_rate;
    TypeOfCredit type_credit;
    std::vector<std::array<long double, 4>> data_for_table;
  };

  void CalculateCredit(CreditCalc::DataForCredit &data_for_credit);
  void AnnuityCredit(long double &sum_credit, long double &amount_months,
                     long double &interest_rate,
                     std::vector<std::array<long double, 4>> data_for_table);
  void DifferentiatedCredit(
      long double &sum_credit, long double &amount_months,
      long double &interest_rate,
      std::vector<std::array<long double, 4>> data_for_table);
};

}  // namespace s21

#endif  // __CREDITCALC_H__
