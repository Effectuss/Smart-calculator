#ifndef CREDITVIEW_H
#define CREDITVIEW_H

#include <controller.h>

#include <QWidget>

namespace Ui {
class CreditView;
}
namespace s21 {
class CreditView : public QWidget {
  Q_OBJECT

 public:
  explicit CreditView(QWidget *parent = nullptr);
  void SetController(Controller *controller);
  void FillDataForCount(CreditCalc::DataForCredit &data_for_credit);
  void SetDefaultSettings();
  void FillTheTable(CreditCalc::DataForCredit &data_for_credit);
  ~CreditView();

 protected:
  void closeEvent(QCloseEvent *event);

 signals:
  void showParent();

 private slots:
  void OnActionCalculateClicked();
  void OnActionCloseClicked();
  void OnActionClearClicked();

 private:
  Ui::CreditView *ui;
  Controller *controller_;
};
}  // namespace s21

#endif  // CREDITVIEW_H
