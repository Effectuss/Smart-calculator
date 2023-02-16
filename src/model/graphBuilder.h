#include <QVector>
#include <QDebug>
#include "mathCalc.h"

namespace s21 {
class GraphBuilder {
 public:
  void FillVectors(QVector<double> &x_vector, QVector<double> &y_vector,
                   std::string expression);
  MathCalc &GetYValueForGraph() { return this->y_value_for_graph_; }

 private:
  MathCalc y_value_for_graph_;
};
}  // namespace s21
