#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QDoubleSpinBox>
#include "controller.h"
#include "qcustomplot.h"

namespace Ui {
class GraphView;
}
namespace s21{
class GraphView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = nullptr);
    void InitWindow(QString &expression_for_graph);
    void SetController(Controller *controller) { this->controller_ = controller; }
    void PaintGraph(const QVector<double>& x_vector, const QVector<double>& y_vector);
    void SetDefaultSettings();
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
};
}

#endif // GRAPHVIEW_H
