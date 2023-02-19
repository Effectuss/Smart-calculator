#ifndef __CREDITCALC_H__
#define __CREDITCALC_H__
#include <array>
#include <cmath>
#include <vector>
namespace s21 {

class CreditCalc {
 public:
  enum TypeOfCredit { kAnnuity = 1, kDifferentiated };

  struct DataForCredit {
    double sum_credit;
    double amount_month;
    double interest_rate;
    TypeOfCredit type_credit;
    double all_money;
    double money_for_bank = 0.0;
    std::vector<std::array<double, 4>> data_for_table;
  };

  void CalculateCredit(CreditCalc::DataForCredit &data_for_credit);
  void AnnuityCredit(double &sum_credit, double amount_months,
                     double &interest_rate,
                     std::vector<std::array<double, 4>> &data_for_table);
  void DifferentiatedCredit(double &sum_credit, double amount_months,
                            double &interest_rate,
                            std::vector<std::array<double, 4>> &data_for_table,
                            double &money_for_bank);
  void AnnuityAllMoneyAndBankMoney(DataForCredit &data_for_credit);
  void DifferentiatedBankMoney(DataForCredit &data_for_credit);

 private:
  double pay_per_month_;
  double after_payment_;
  double interest_per_month_;
  double pay_by_interest_;
  double body_of_credit_;
};

}  // namespace s21

#endif  // __CREDITCALC_H__
