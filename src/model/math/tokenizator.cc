#include "tokenizator.h"

namespace s21 {

std::list<Token>& Tokenizator::GetListToken() { return this->l_tokens_; }

void Tokenizator::ToTokens(std::string& expression, const double& x) {
  this->l_tokens_.clear();
  for (std::size_t i = 0; i < expression.length(); ++i) {
    if (TokenizationX(expression, x, i)) continue;
    if (TokenizationNumber(expression, i)) continue;
    if (TokenizationOpenParen(expression, i)) continue;
    if (TokenizationCloseParen(expression, i)) continue;
    if (TokenizationOperator(expression, i)) continue;
    if (TokenizationFunction(expression, i)) continue;
  }
  if (this->l_tokens_.empty()) {
    this->l_tokens_.push_back(Token(Token::TypeTokens::kNumber, "0.0"));
  }
}

bool Tokenizator::TokenizationX(const std::string& expression, const double& x,
                                const std::size_t& i) {
  if (expression[i] == 'x') {
    this->l_tokens_.push_back(
        Token(Token::TypeTokens::kNumber, std::to_string(x)));
    return true;
  }
  return false;
}

bool Tokenizator::TokenizationNumber(std::string& expression, std::size_t& i) {
  if (isdigit(expression[i]) || expression[i] == '.') {
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
    if (!Tokenizator::IsCorrectNumber(
            expression.substr(i, tmp_move_along - i))) {
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::kNumber,
                expression.substr(i, tmp_move_along - i)));
      i += this->l_tokens_.back().GetTokenString().length() - 1;
      return true;
    }
  }
  return false;
}

bool Tokenizator::TokenizationOperator(std::string& expression,
                                       std::size_t& i) {
  if (!Tokenizator::IsOperator(expression[i])) {
    auto tmp_move_along = expression.find_first_not_of("+-^*/mod", i);
    std::string token = expression.substr(i, tmp_move_along - i);
    if (token == "mod" || token == "/" || token == "*") {
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::kBinaryOperator, token, 3));
    } else if (token == "+" || token == "-") {
      if (this->l_tokens_.empty() || this->l_tokens_.back().GetType() ==
                                         Token::TypeTokens::kOpenParenthesis) {
        if (token == "+") {
          this->l_tokens_.push_back(
              Token(Token::TypeTokens::kUnaryOperator, "A", 5));
        } else {
          this->l_tokens_.push_back(
              Token(Token::TypeTokens::kUnaryOperator, "C", 5));
        }
      } else {
        this->l_tokens_.push_back(
            Token(Token::TypeTokens::kBinaryOperator, token, 2));
      }
    } else if (token == "^") {
      this->l_tokens_.push_back(
          Token(Token::TypeTokens::kBinaryOperator, token, 4));
    } else {
      throw std::invalid_argument(
          "Binary operators cannot be repeated or unknown operator");
    }
    i += this->l_tokens_.back().GetTokenString().length() - 1;
    return true;
  }
  return false;
}

bool Tokenizator::TokenizationFunction(std::string& expression,
                                       std::size_t& i) {
  if (!Tokenizator::IsFunction(expression[i])) {
    auto tmp_move_along = expression.find_first_not_of("cosinatlgqr", i) - i;
    if (!Tokenizator::IsCorrectFunction(expression.substr(i, tmp_move_along),
                                        kFunction_)) {
      this->l_tokens_.push_back(Token(Token::TypeTokens::kFunction,
                                      expression.substr(i, tmp_move_along), 6));
      i += this->l_tokens_.back().GetTokenString().length() - 1;
      return true;
    }
  }
  return false;
}

bool Tokenizator::TokenizationOpenParen(const std::string& expression,
                                        std::size_t& i) {
  if (expression[i] == '(') {
    this->l_tokens_.push_back(
        Token(Token::TypeTokens::kOpenParenthesis, "(", 0));
    i += this->l_tokens_.back().GetTokenString().length() - 1;
    return true;
  }
  return false;
}

bool Tokenizator::TokenizationCloseParen(const std::string& expression,
                                         std::size_t& i) {
  if (expression[i] == ')') {
    this->l_tokens_.push_back(
        Token(Token::TypeTokens::kCloseParenthesis, ")", 0));
    i += this->l_tokens_.back().GetTokenString().length() - 1;
    return true;
  }
  return false;
}

bool Tokenizator::IsCorrectFunction(const std::string& expression,
                                    const std::vector<std::string>& function) {
  if (std::any_of(
          function.cbegin(), function.cend(),
          [&expression](const std::string& el) { return el == expression; })) {
    return false;
  } else {
    throw std::invalid_argument("Name of available functions is incorrect");
  }
}

bool Tokenizator::IsCorrectNumber(const std::string& number) {
  size_t pos;
  [[maybe_unused]] double tmp = std::stod(number, &pos);
  if (pos == number.length()) {
    return false;
  } else {
    throw std::invalid_argument("The number you entered is incorrect");
  }
  return true;
}

bool Tokenizator::IsFunction(const char& symb) {
  if (symb >= 'a' && symb <= 'z' && symb != 'm') return false;
  return true;
};

bool Tokenizator::IsOperator(const char& symb) {
  if (symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == 'm' ||
      symb == '^')
    return false;
  return true;
}

}  // namespace s21
