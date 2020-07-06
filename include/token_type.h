#ifndef TOKENTYPE
#define TOKENTYPE

typedef enum {
  ILLEGAL,
  EOFF,

  IDENT,
  NUMBER,

  ASSIGN,
  PLUS,

  COMMA,
  SEMICOLON,
  COLON,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  FUNCTION,
  LET,
  INT,
  RETURN,
} TokenType;

#endif 
