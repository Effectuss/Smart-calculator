#include "calcView.h"

#include "ui_calcView.h"

CalcView::CalcView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalcView), graph_window(new GraphView()),
      credit_calc(new CreditView()) {
  ui->setupUi(this);

  // Solo symb
  connect(ui->num0, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num1, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num2, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num3, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num4, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num5, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num6, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num7, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num8, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->num9, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->point, SIGNAL(clicked()), this, SLOT(AddNotFunction()));

  connect(ui->actionCloseBracket, SIGNAL(clicked()), this,
          SLOT(AddNotFunction()));
  connect(ui->actionOpenBracket, SIGNAL(clicked()), this,
          SLOT(AddNotFunction()));

  connect(ui->actionDiv, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->actionPlus, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->actionMult, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->actionMinus, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->actionPow, SIGNAL(clicked()), this, SLOT(AddNotFunction()));

  connect(ui->xButton, SIGNAL(clicked()), this, SLOT(AddNotFunction()));
  connect(ui->numerExp, SIGNAL(clicked()), this, SLOT(AddNotFunction()));

  // Function
  connect(ui->actionAcos, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionAsin, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionAtan, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionCos, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionLn, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionLog, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionMod, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionSin, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionSqrt, SIGNAL(clicked()), this, SLOT(AddFunction()));
  connect(ui->actionTan, SIGNAL(clicked()), this, SLOT(AddFunction()));

  // = Calculate
  connect(ui->actionCalc, SIGNAL(clicked()), this, SLOT(StartCalculacte()));

  // Delete All
  connect(ui->actionDeleteAll, SIGNAL(clicked()), this,
          SLOT(ClearInputPanel()));

  // Delete One Symb
  connect(ui->actionDeleteOne, SIGNAL(clicked()), this, SLOT(DeleteOneSymb()));

  // Menu connect
  connect(ui->actionGraph, SIGNAL(triggered()), this,
          SLOT(OnActionGraphTriggered()));
  connect(ui->actionMath, SIGNAL(triggered()), this,
          SLOT(OnActionMathTriggered()));
  connect(ui->actionCredit, SIGNAL(triggered()), this,
          SLOT(OnActionCreditTriggered()));

  // closeEvent connect
  connect(graph_window, SIGNAL(showParent()), this, SLOT(show()));
  connect(credit_calc, SIGNAL(showParent()), this, SLOT(show()));
}

void CalcView::SetController(Controller *controller) {
  this->controller_ = controller;
}

void CalcView::CheckAndChangeStyleLabel() {
  if (this->input_label_.length() == 50) {
    ui->inputPanel->setStyleSheet(
        "font: 16pt; border: 1 solid #b8b8b8; background-color: #fff;");
  } else if (this->input_label_.length() == 80) {
    ui->inputPanel->setStyleSheet(
        "font: 13pt; border: 1 solid #b8b8b8; background-color: #fff;");
  } else if (this->input_label_.length() == 100) {
    ui->inputPanel->setStyleSheet(
        "font: 12pt; border: 1 solid #b8b8b8; background-color: #fff;");
  }
}

void CalcView::AddFunctionOrNot(QPushButton *button, bool is_func) {
  if (!is_func || button->text() == "mod") {
    this->input_label_ += button->text();
  } else {
    this->input_label_ += button->text() + '(';
  }
  this->CheckAndChangeStyleLabel();
  ui->inputPanel->setText(this->input_label_);
}

void CalcView::AddNotFunction() {
  QPushButton *button = static_cast<QPushButton *>(QObject::sender());
  AddFunctionOrNot(button, false);
}

void CalcView::AddFunction() {
  QPushButton *button = static_cast<QPushButton *>(QObject::sender());
  AddFunctionOrNot(button, true);
}

void CalcView::ClearInputPanel() {
  this->input_label_.resize(0);
  ui->inputPanel->setStyleSheet(
      "font: 20pt; border: 1 solid #b8b8b8; background-color: #fff;");
  ui->inputPanel->setText(this->input_label_);
}

void CalcView::DeleteOneSymb() {
  this->input_label_.resize(this->input_label_.length() - 1);
  ui->inputPanel->setText(this->input_label_);
}

void CalcView::StartCalculacte() {
  std::string input_str = input_label_.toUtf8().constData();
  if (this->input_label_.indexOf("x") >= 0) {
    this->value_x_ = ui->xValue->value();
  }
  try {
    double result = this->controller_->CalculateMath(input_str, this->value_x_);
    input_str = std::to_string(result);
    this->input_label_ = this->input_label_.fromStdString(input_str);
    ui->inputPanel->setStyleSheet(
        "font: 20pt; border: 1 solid #b8b8b8; background-color: #fff;");
    ui->inputPanel->setText(this->input_label_);
    this->input_label_.resize(this->input_label_.length());
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void CalcView::OnActionGraphTriggered() {
  try {
    graph_window->SetController(this->controller_);
    graph_window->InitWindow(this->input_label_);
    this->hide();
    credit_calc->hide();
    graph_window->show();
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning",
                          "Invalid expression for build grahp");
  }
}

void CalcView::OnActionMathTriggered() {
  credit_calc->hide();
  graph_window->hide();
  this->show();
}

void CalcView::OnActionCreditTriggered() {
  credit_calc->SetController(this->controller_);
  this->hide();
  graph_window->hide();
  credit_calc->show();
}

CalcView::~CalcView() { delete ui; }
