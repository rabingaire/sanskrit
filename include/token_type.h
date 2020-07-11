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
  VOID,

  ILLEGAL,
  EOFF,
} TokenType;

#endif 
