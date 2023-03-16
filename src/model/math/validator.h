#ifndef __VALIDATOR_H__
#define __VALIDATOR_H__

#include "tokenizator.h"

class Validator {
public:
  void Validation(std::list<Token> &token);

  static bool ValidForFirst(const Token &current);
  static bool ValidForLast(const Token &current);

  static void ValidForNumber(const Token &previous);
  static void ValidForFunction(const Token &previous);
  static void ValidForOpenParenthesis(const Token &previous);
  static void ValidForCloseParenthesis(const Token &previous);
  static void ValidForBinOperator(const Token &previous);

  bool AdditionalCheckForBrackets(const int &close, const int &open);
};

#endif // __VALIDATOR_H__
