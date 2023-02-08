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
    } else if (expression[i] == '(') {
      this->v_tokens_.push_back(
          Token(Token::TypeTokens::OPEN_PARENTHESIS, "("));
    } else if (expression[i] == ')') {
      this->v_tokens_.push_back(
          Token(Token::TypeTokens::CLOSE_PARENTHESIS, ")"));
    } else if (!Token::IsOperator(expression[i])) {
      auto tmp_move_along = expression.find_first_not_of("+-^*/mod", i);
      std::string token = expression.substr(i, tmp_move_along - i);
      if (token == "mod" || token == "/" || token == "*") {
        this->v_tokens_.push_back(
            Token(Token::TypeTokens::BINARY_OPERATOR, token, 3));
      } else if (token == "+" || token == "-") {
        this->v_tokens_.push_back(
            Token(Token::TypeTokens::BINARY_OPERATOR, token, 2));
      } else if (token == "^") {
        this->v_tokens_.push_back(
            Token(Token::TypeTokens::BINARY_OPERATOR, token, 4));
      } else {
        throw std::invalid_argument(
            "Binary operators cannot be repeated or unknown operator");
      }
    } else if (!Token::IsFunction(expression[i])) {
      auto tmp_move_along = expression.find_first_not_of("cosinatlgqr", i);
      this->v_tokens_.push_back(Token(Token::TypeTokens::FUNCTION,
                                      expression.substr(i, tmp_move_along - i),
                                      5));

    }
    i += this->v_tokens_.back().GetTokenString().length() - 1;
  }
}

}  // namespace s21s
