#include "calcModel.h"

namespace s21 {
std::string CalcModel::GetInputStr() const { return output_result_; }

void CalcModel::SetInputStr(std::string& input_str) {
  this->output_result_ = input_str;
}

void CalcModel::ToTokens(std::string& expression, double& x) {
  auto i = 0;
  for (auto i = 0; i < expression.length(); ++i) {
    if (expression[i] == 'x') {
      this->v_tokens_.push_back(
          Token(Token::TypeTokens::NUMBER, std::to_string(x)));
    } else if (isdigit(expression[i]) || expression[i] == '.') {
      auto tmp_move_along = expression.find_first_not_of(".0123456789e", i);
      if (expression[tmp_move_along - 1] == 'e') {
        while (expression[tmp_move_along] == '-' ||
               expression[tmp_move_along] == '+') {
          ++tmp_move_along;
        }
        while (isdigit(expression[tmp_move_along])) {
          ++tmp_move_along;
        }
      }
      this->v_tokens_.push_back(Token(
          Token::TypeTokens::NUMBER, expression.substr(i, tmp_move_along - i)));
      i += this->v_tokens_.back().GetTokenString().length() - 1;
    } else if (expression[i] == '(') {
      this->v_tokens_.push_back(
          Token(Token::TypeTokens::OPEN_PARENTHESIS, ")"));
    } else if (expression[i] == ')') {
      this->v_tokens_.push_back(
          Token(Token::TypeTokens::CLOSE_PARENTHESIS, "("));
    }
    // else if () {
    // }
  }
}

}  // namespace s21
