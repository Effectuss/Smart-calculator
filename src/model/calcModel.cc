#include "calcModel.h"

namespace s21 {

void CalcModel::ToTokens(std::string& expression, double& x) {
  auto i = 0;
  for (auto i = 0; i < expression.length(); ++i) {
    if (expression[i] == 'x') {
      // Токенизация для Х
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::NUMBER, std::to_string(x)));
    } else if (isdigit(expression[i]) || expression[i] == '.') {
      // Токенизация для Числа
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
      this->l_tokens_.push_back(Token(
          Token::TypeTokens::NUMBER, expression.substr(i, tmp_move_along - i)));

    } else if (expression[i] == '(') {
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::OPEN_PARENTHESIS, "("));
    } else if (expression[i] == ')') {
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::CLOSE_PARENTHESIS, ")"));

    } else if (!Token::IsOperator(expression[i])) {
      // Токенизация для Оператора
      auto tmp_move_along = expression.find_first_not_of("+-^*/mod", i);
      std::string token = expression.substr(i, tmp_move_along - i);
      if (token == "mod" || token == "/" || token == "*") {
        this->l_tokens_.push_back(
            Token(Token::TypeTokens::BINARY_OPERATOR, token, 3));
      } else if (token == "+" || token == "-") {
        if (this->l_tokens_.empty() ||
            this->l_tokens_.back().GetType() ==
                Token::TypeTokens::OPEN_PARENTHESIS) {
          this->l_tokens_.push_back(
              Token(Token::TypeTokens::UNARY_OPERATOR, token, 5));
        } else {
          this->l_tokens_.push_back(
              Token(Token::TypeTokens::BINARY_OPERATOR, token, 2));
        }
      } else if (token == "^") {
        this->l_tokens_.push_back(
            Token(Token::TypeTokens::BINARY_OPERATOR, token, 4));
      } else {
        throw std::invalid_argument(
            "Binary operators cannot be repeated or unknown operator");
      }

    } else if (!Token::IsFunction(expression[i])) {
      // Токенизация для функций
      auto tmp_move_along = expression.find_first_not_of("cosinatlgqr", i);
      this->l_tokens_.push_back(Token(Token::TypeTokens::FUNCTION,
                                      expression.substr(i, tmp_move_along - i),
                                      6));
    }
    i += this->l_tokens_.back().GetTokenString().length() - 1;
  }
}

bool CalcModel::TokenizationNumber() {}
bool CalcModel::TokenizationX() {}
bool CalcModel::TokenizationOperator() {}
bool CalcModel::TokenizationFunction() {}
bool CalcModel::TokenizationOpenParen() {}
bool CalcModel::TokenizationCloseParen() {}

void CalcModel::Validation() {
  for (auto& el : this->l_tokens_) {
  }
}

}  // namespace s21
