#ifndef __CREDITCALC_H__
#define __CREDITCALC_H__
#include <array>
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
    std::vector<std::array<double, 4>> data_for_table;
  };

    void CalculateCredit(CreditCalc::DataForCredit &data_for_credit);
    void AnnuityCredit(CreditCalc::DataForCredit &data_for_credit);
    void DifferentiatedCredit(CreditCalc::DataForCredit &data_for_credit);

};

}  // namespace s21

#endif  // __CREDITCALC_H__
