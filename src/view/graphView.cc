#include "graphView.h"
#include "ui_graphView.h"
#include <QDebug>

namespace s21 {
GraphView::GraphView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphView)
{
    ui->setupUi(this);
    connect(ui->actionBuild, SIGNAL(clicked()), this, SLOT(OnActionBuild()));
    connect(ui->actionClose, SIGNAL(clicked()), this, SLOT(OnActionClose()));
    connect(ui->actionClear, SIGNAL(clicked()), this, SLOT(OnActionClear()));

}

void GraphView::InitWindow(QString &expression_for_graph)
{
    ui->graphWidget->xAxis->setRange(ui->valueMinX->value(), ui->valueMaxX->value());
    ui->graphWidget->yAxis->setRange(ui->valueMinY->value(), ui->valueMaxY->value());
    ui->expressionGraph->setText(expression_for_graph);
    controller_->FillVectors(this->x_vector, this->y_vector, expression_for_graph.toStdString());
//    this->PaintGraph(this->x_vector, this->y_vector);
}

void GraphView::SetDefaultSettings()
{
    ui->colorSet->setCurrentIndex(0);
    ui->expressionGraph->clear();
    ui->valueMaxX->setValue(15.0);
    ui->valueMaxY->setValue(15.0);
    ui->valueMinX->setValue(-15.0);
    ui->valueMinY->setValue(-15.0);
    ui->valueStep->setValue(0.01);
    ui->graphWidget->xAxis->setRange(ui->valueMinX->value(), ui->valueMaxX->value());
    ui->graphWidget->yAxis->setRange(ui->valueMinY->value(), ui->valueMaxY->value());
    ui->graphWidget->clearGraphs();
    ui->graphWidget->addGraph();
}

void GraphView::PaintGraph(const QVector<double>& x_vector, const QVector<double>& y_vector) {

}

void GraphView::closeEvent(QCloseEvent *event)
{
    this->OnActionClose();
}

void GraphView::OnActionBuild()
{

}

void GraphView::OnActionClose()
{
    this->SetDefaultSettings();
    emit showParent();
    this->close();
}

void GraphView::OnActionClear()
{
    this->SetDefaultSettings();
}

GraphView::~GraphView()
{
    delete ui;
}

}
