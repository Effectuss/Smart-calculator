#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class CalcView; }
QT_END_NAMESPACE

class CalcView : public QMainWindow
{
    Q_OBJECT

public:
    CalcView(QWidget *parent = nullptr);
    ~CalcView();

private:
    Ui::CalcView *ui;
};
#endif // SMARTCALC_H
