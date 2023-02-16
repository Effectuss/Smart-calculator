#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include "controller.h"

namespace Ui {
class GraphView;
}
namespace s21{
class GraphView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = nullptr);
    void InitWindow();
    void SetController(Controller *controller) { this->controller_ = controller; }
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
