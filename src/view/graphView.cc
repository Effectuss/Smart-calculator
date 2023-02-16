#include "graphView.h"
#include "ui_graphView.h"

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

void GraphView::InitWindow()
{

}

void GraphView::closeEvent(QCloseEvent *event)
{
    emit showParent();
    this->close();
}

void GraphView::OnActionBuild()
{

}

void GraphView::OnActionClose()
{

}

void GraphView::OnActionClear()
{

}

GraphView::~GraphView()
{
    delete ui;
}

}
