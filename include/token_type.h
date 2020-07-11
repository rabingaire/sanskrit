#ifndef TOKENTYPE
#define TOKENTYPE

typedef enum {
  ASSIGN,
  PLUS,

  COMMA,
  SEMICOLON,
  COLON,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  IDENT,
  NUMBER,

  FUNCTION,
  LET,
  INT,
  RETURN,

  ILLEGAL,
  EOFF,
} TokenType;

#endif 
