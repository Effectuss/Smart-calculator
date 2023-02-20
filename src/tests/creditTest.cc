#include <gtest/gtest.h>

#include <cstdio>

#include "../model/model.h"

namespace s21 {
typedef std::vector<std::array<double, 4>> test_type;

void fill_data_for_credit(CreditCalc::DataForCredit &data, double sum_credit,
                          double amount_month, double interest_rate,
                          CreditCalc::TypeOfCredit type) {
  data.sum_credit = sum_credit;
  data.amount_month = amount_month;
  data.interest_rate = interest_rate;
  data.type_credit = type;
}

void compare_data(test_type &data_from_calcus, test_type &my_data) {
  for (size_t i = 0; i < data_from_calcus.size(); ++i) {
    for (size_t j = 0; j < data_from_calcus.at(0).size(); ++j) {
      char buffer_my[300] = "\0";
      char buffer_calcus[300] = "\0";
      sprintf(buffer_my, "%.1f", my_data.at(i).at(j));
      sprintf(buffer_calcus, "%.1f", data_from_calcus.at(i).at(j));
      ASSERT_STREQ(buffer_my, buffer_calcus);
    }
  }
}

TEST(CreditCalc, test1) {
  Model model;
  CreditCalc::DataForCredit data;
  fill_data_for_credit(data, 3'000'000.0, 24.0, 13.0,
                       CreditCalc::TypeOfCredit::kAnnuity);
  model.GetCreditCalc().CalculateCredit(data);
  test_type from_calcus = {{142625.47, 110125.47, 32500.00, 2889874.53},
                           {142625.47, 111318.49, 31306.97, 2778556.04},
                           {142625.47, 112524.44, 30101.02, 2666031.59},
                           {142625.47, 113743.46, 28882.01, 2552288.14},
                           {142625.47, 114975.68, 27649.79, 2437312.46},
                           {142625.47, 116221.25, 26404.22, 2321091.21},
                           {142625.47, 117480.31, 25145.15, 2203610.87},
                           {142625.47, 118753.02, 23872.45, 2084857.85},
                           {142625.47, 120039.51, 22585.96, 1964818.4},
                           {142625.47, 121339.94, 21285.53, 1843478.40},
                           {142625.47, 122654.5, 19971.02, 1720824.0},
                           {142625.47, 123983.21, 18642.26, 1596840.8},
                           {142625.47, 125326.36, 17299.11, 1471514.38},
                           {142625.47, 126684.06, 15941.41, 1344830.4},
                           {142625.47, 128056.47, 14569.00, 1216773.85},
                           {142625.47, 129443.75, 13181.72, 1087330.10},
                           {142625.47, 130846.06, 11779.41, 956484.1},
                           {142625.47, 132263.56, 10361.91, 824220.48},
                           {142625.47, 133696.41, 8929.06, 690524.07},
                           {142625.47, 135144.79, 7480.68, 555379.28},
                           {142625.47, 136608.86, 6016.61, 418770.5},
                           {142625.47, 138088.79, 4536.68, 280681.7},
                           {142625.47, 139584.7, 3040.72, 141096.88},
                           {142625.47, 141096.92, 1528.55, -0.00}};
  compare_data(from_calcus, data.data_for_table);
}
}  // namespace s21