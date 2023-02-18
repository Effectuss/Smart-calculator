#ifndef __CALCVIEW_H__
#define __CALCVIEW_H__

#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <qcustomplot.h>

#include "graphView.h"
#include "creditView.h"
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CalcView;
}
QT_END_NAMESPACE

namespace s21 {
class CalcView : public QMainWindow {
  Q_OBJECT

 public:
  CalcView(QWidget *parent = nullptr);
  void SetController(Controller *controller);
  Controller* GetController() {return this->controller_;}
  void CheckAndChangeStyleLabel();
  void AddFunctionOrNot(QPushButton *button, bool is_func);
  ~CalcView();


private slots:
    void OnActionGraphTriggered();
    void OnActionMathTriggered();
    void OnActionCreditTriggered();
    void AddNotFunction();
    void AddFunction();
    void ClearInputPanel();
    void DeleteOneSymb();
    void StartCalculacte();

private:
  Ui::CalcView *ui;
  GraphView *graph_window;
  CreditView *credit_calc;
  Controller *controller_;
  QString input_label_;
  double value_x_;
};
}  // namespace s21

#endif  // __CALCVIEW_H__
