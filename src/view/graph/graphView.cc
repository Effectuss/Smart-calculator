#include "graphView.h"

#include <QDebug>

#include "ui_graphView.h"

namespace s21 {
GraphView::GraphView(QWidget *parent) : QWidget(parent), ui(new Ui::GraphView) {
  ui->setupUi(this);
  connect(ui->actionBuild, SIGNAL(clicked()), this, SLOT(OnActionBuild()));
  connect(ui->actionClose, SIGNAL(clicked()), this, SLOT(OnActionClose()));
  connect(ui->actionClear, SIGNAL(clicked()), this, SLOT(OnActionClear()));
  ui->graphWidget->setInteraction(QCP::iRangeZoom, true);
  ui->graphWidget->setInteraction(QCP::iRangeDrag, true);
}

void GraphView::InitWindow(QString expression_for_graph) {
  this->x_points.clear();
  this->y_points.clear();
  this->step = ui->valueStep->value();
  this->x_begin = ui->valueMinX->value();
  this->x_end = ui->valueMaxX->value() + this->step;
  ui->graphWidget->xAxis->setRange(this->x_begin, this->x_end);
  ui->graphWidget->yAxis->setRange(ui->valueMinY->value(),
                                   ui->valueMaxY->value());
  ui->expressionGraph->setText(expression_for_graph);
  this->BuildPointsForGraph(expression_for_graph);
  this->PaintGraph();
}

void GraphView::SetDefaultSettings() {
  ui->expressionGraph->clear();
  this->x_points.clear();
  this->y_points.clear();
  ui->graphWidget->clearGraphs();
  ui->graphWidget->replot();
}

void GraphView::BuildPointsForGraph(QString &expression_for_graph) {
  double tmp_y = 0.0;
  std::string expression_std = expression_for_graph.toStdString();
  double x = this->x_begin;
  int n = (this->x_end - this->x_begin) / this->step;
  for (int i = 0; i < n; x += this->step, ++i) {
    tmp_y = this->controller_->CalculateMath(expression_std, x);
    this->x_points.push_back(x);
    this->y_points.push_back(tmp_y);
  }
}

void GraphView::PaintGraph() {
  ui->graphWidget->clearGraphs();
  ui->graphWidget->addGraph();
  ui->graphWidget->graph(0)->setPen(QPen(QColor(ui->colorSet->currentText())));
  ui->graphWidget->graph(0)->setLineStyle(
      QCPGraph::LineStyle(QCPGraph::lsNone));
  ui->graphWidget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDot, 5.0));
  ui->graphWidget->graph(0)->addData(this->x_points, this->y_points);
  ui->graphWidget->replot();
}

void GraphView::closeEvent(QCloseEvent *event) { this->OnActionClose(); }

void GraphView::OnActionBuild() {
  try {
    this->InitWindow(this->ui->expressionGraph->text());
  } catch (std::exception &e) {
    QMessageBox::critical(this, "Warning",
                          "Invalid expression for build grahp");
  }
}

void GraphView::SetController(Controller *controller) {
  this->controller_ = controller;
}

void GraphView::OnActionClose() {
  this->SetDefaultSettings();
  emit showParent();
  this->close();
}

void GraphView::OnActionClear() { this->SetDefaultSettings(); }

GraphView::~GraphView() { delete ui; }

}  // namespace s21
