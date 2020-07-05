#ifndef TOKENTYPE
#define TOKENTYPE

typedef enum {
  ILLEGAL,
  EOFF,

  IDENT,
  INT,

  ASSIGN,
  PLUS,

  COMMA,
  SEMICOLON,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  FUNCTION,
  LET
} TokenType;

#endif 
