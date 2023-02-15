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
#include "calcController.h"

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
  void SetController(CalcController *controller);
  void CheckAndChangeStyleLabel();
  void AddFunctionOrNot(QPushButton *button, bool is_func);
  ~CalcView();

 public slots:
  void AddNotFunction();
  void AddFunction();
  void ClearInputPanel();
  void DeleteOneSymb();
  void StartCalculacte();

private slots:
    void on_actionGraph_triggered();

private:
  Ui::CalcView *ui;
  GraphView *graph_window;
  CalcController *controller_;
  QString input_label_;
  double value_x_;
};
}  // namespace s21

#endif  // __CALCVIEW_H__
