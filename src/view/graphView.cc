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
    this->step = ui->valueStep->value();
    this->x_begin =ui->valueMinX->value();
    this->x_end =ui->valueMaxX->value() + this->step;
    ui->graphWidget->xAxis->setRange(this->x_begin, this->x_end);
    ui->graphWidget->yAxis->setRange(ui->valueMinY->value(), ui->valueMaxY->value());
    ui->expressionGraph->setText(expression_for_graph);
    this->BuildPointsForGraph(expression_for_graph);
    this->PaintGraph();
}

void GraphView::SetController(Controller *controller)
{
 this->controller_ = controller;
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
//    ui->graphWidget->addGraph();
}

void GraphView::BuildPointsForGraph(QString &expression_for_graph)
{
    double tmp_y = 0.0;
    std::string expression_std = expression_for_graph.toStdString();
    for(double x = this->x_begin; x <= this->x_end; x += this->step) {
        tmp_y = this->controller_->CalculateMath(expression_std,x);
        this->x_points.push_back(x);
        this->y_points.push_back(tmp_y);
    }
}

void GraphView::PaintGraph() {

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
