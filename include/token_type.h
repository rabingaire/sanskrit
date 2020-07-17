#ifndef TOKENTYPE
#define TOKENTYPE

typedef enum {
  ASSIGN,
  COLON_ASSIGN,
  EQUAL,
  NOT_EQUAL,
  AND,
  OR,

  PLUS,
  PLUS_ASSIGN,
  MINUS,
  MINUS_ASSIGN,
  EXCLAMATION,
  ASTERISK,
  ASTERISK_ASSIGN,
  SLASH,
  SLASH_ASSIGN,
  INCREMENT,
  DECREMENT,

  COMMA,
  SEMICOLON,
  COLON,
  LESS_THEN,
  LESS_THEN_EQUAL,
  GREATER_THEN,
  GREATER_THEN_EQUAL,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  IDENT,
  INTEGER,
  STRING,

  FUNCTION,
  LET,
  INT,
  RETURN,
  VOID,
  FOR,
  BOOL,
  IF,
  ELSE,
  RANGE,
  STR,

  ILLEGAL,
  EOFF,
} TokenType;

#endif 
