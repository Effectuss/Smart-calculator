#ifndef __VALIDATOR_H__
#define __VALIDATOR_H__

#include "tokenizator.h"
namespace s21 {
class Validator {
 public:
  Validator() : count_close_parenthesis{0}, count_open_parenthesis{0} {}
  void Validation(std::list<Token>& token);

  static bool ValidForFirst(const Token& current);
  static bool ValidForLast(const Token& current);

  static void ValidForNumber(const Token& previous);
  static void ValidForFunction(const Token& previous);
  static void ValidForOpenParenthesis(const Token& previous);
  static void ValidForCloseParenthesis(const Token& previous);
  static void ValidForBinOperator(const Token& previous);
  static void ValidForUnaryOperator(const Token& previous);

 private:
  int count_open_parenthesis;
  int count_close_parenthesis;
};
}  // namespace s21
#endif  // __VALIDATOR_H__
