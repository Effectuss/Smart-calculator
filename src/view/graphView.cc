#include "graphView.h"
#include "ui_graphView.h"

namespace s21 {
GraphView::GraphView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphView)
{
    ui->setupUi(this);
}

GraphView::~GraphView()
{
    delete ui;
}

void GraphView::closeEvent(QCloseEvent *event)
{
    emit showParent();
    this->close();
}


void GraphView::on_pushButton_clicked()
{

}

}
