package com.craftinginterpreters.lox;

/**
 * Loxプログラミング言語におけるトークンを表す
 * トークンは、キーワード、識別子、演算子などの言語の単一要素を表すレキシカルユニット
 */
class Token {
  final TokenType type;
  final String lexeme;
  final Object literal;
  final int line;

  Token (TokenType type, String lexeme, Object literal, int line) {
    this.type = type;
    this.lexeme = lexeme;
    this.literal = literal;
    this.line = line;
  }

  /**
   * トークンの文字列表現を返します。
   * @return トークンの文字列表現
   */
  public String toString () {
    return type + " " + lexeme + " " + literal;
  }
}