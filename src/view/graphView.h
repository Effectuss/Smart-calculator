#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>

namespace Ui {
class GraphView;
}
namespace s21{
class GraphView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = nullptr);
    ~GraphView();


protected:
    void closeEvent(QCloseEvent *event);

signals:
    void showParent();

private:
    Ui::GraphView *ui;
};
}

#endif // GRAPHVIEW_H
