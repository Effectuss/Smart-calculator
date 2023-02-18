#ifndef CREDITVIEW_H
#define CREDITVIEW_H

#include <QWidget>
#include <controller.h>

namespace Ui {
class CreditView;
}
namespace s21 {
class CreditView : public QWidget
{
    Q_OBJECT

public:
    explicit CreditView(QWidget *parent = nullptr);
    void SetController(Controller *controller);
    void InitWindow();
    ~CreditView();

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void showParent();

private:
    Ui::CreditView *ui;
    Controller *controller_;
};
}

#endif // CREDITVIEW_H
