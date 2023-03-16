#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QDoubleSpinBox>
#include <QVector>
#include <QWidget>

#include "controller.h"
#include "qcustomplot.h"

namespace Ui {
class GraphView;
}

class GraphView : public QWidget {
  Q_OBJECT

 public:
  explicit GraphView(QWidget *parent = nullptr);
  void InitWindow(QString expression_for_graph);
  void SetController(Controller *controller);
  void SetDefaultSettings();
  void BuildPointsForGraph(QString &expression_for_graph);
  void PaintGraph();

  ~GraphView();

 protected:
  void closeEvent(QCloseEvent *event);

 signals:
  void showParent();

 private slots:
  void OnActionBuild();
  void OnActionClose();
  void OnActionClear();

 private:
  Ui::GraphView *ui;
  Controller *controller_;
  QVector<double> x_points;
  QVector<double> y_points;
  double step;
  double x_begin;
  double x_end;
};

#endif  // GRAPHVIEW_H
