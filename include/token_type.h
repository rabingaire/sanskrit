#ifndef SK_TOKEN_TYPE_H
#define SK_TOKEN_TYPE_H

typedef enum
{
  TOKEN_ASSIGN,
  TOKEN_COLON_ASSIGN,
  TOKEN_EQUAL,
  TOKEN_NOT_EQUAL,
  TOKEN_AND,
  TOKEN_OR,

  TOKEN_PLUS,
  TOKEN_PLUS_ASSIGN,
  TOKEN_MINUS,
  TOKEN_MINUS_ASSIGN,
  TOKEN_EXCLAMATION,
  TOKEN_ASTERISK,
  TOKEN_ASTERISK_ASSIGN,
  TOKEN_SLASH,
  TOKEN_SLASH_ASSIGN,
  TOKEN_INCREMENT,
  TOKEN_DECREMENT,

  TOKEN_COMMA,
  TOKEN_SEMICOLON,
  TOKEN_COLON,
  TOKEN_LESS_THEN,
  TOKEN_LESS_THEN_EQUAL,
  TOKEN_GREATER_THEN,
  TOKEN_GREATER_THEN_EQUAL,

  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_LBRACE,
  TOKEN_RBRACE,

  TOKEN_IDENT,
  TOKEN_INTEGER,
  TOKEN_STRING,

  TOKEN_FUNCTION,
  TOKEN_LET,
  TOKEN_INT,
  TOKEN_RETURN,
  TOKEN_VOID,
  TOKEN_FOR,
  TOKEN_BOOL,
  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_RANGE,
  TOKEN_STR,

  TOKEN_ILLEGAL,
  TOKEN_EOF,
} token_type_T;

static char *token_type_string[] = {
    "TOKEN_ASSIGN",
    "TOKEN_COLON_ASSIGN",
    "TOKEN_EQUAL",
    "TOKEN_NOT_EQUAL",
    "TOKEN_AND",
    "TOKEN_OR",

    "TOKEN_PLUS",
    "TOKEN_PLUS_ASSIGN",
    "TOKEN_MINUS",
    "TOKEN_MINUS_ASSIGN",
    "TOKEN_EXCLAMATION",
    "TOKEN_ASTERISK",
    "TOKEN_ASTERISK_ASSIGN",
    "TOKEN_SLASH",
    "TOKEN_SLASH_ASSIGN",
    "TOKEN_INCREMENT",
    "TOKEN_DECREMENT",

    "TOKEN_COMMA",
    "TOKEN_SEMICOLON",
    "TOKEN_COLON",
    "TOKEN_LESS_THEN",
    "TOKEN_LESS_THEN_EQUAL",
    "TOKEN_GREATER_THEN",
    "TOKEN_GREATER_THEN_EQUAL",

    "TOKEN_LPAREN",
    "TOKEN_RPAREN",
    "TOKEN_LBRACE",
    "TOKEN_RBRACE",

    "TOKEN_IDENT",
    "TOKEN_INTEGER",
    "TOKEN_STRING",

    "TOKEN_FUNCTION",
    "TOKEN_LET",
    "TOKEN_INT",
    "TOKEN_RETURN",
    "TOKEN_VOID",
    "TOKEN_FOR",
    "TOKEN_BOOL",
    "TOKEN_IF",
    "TOKEN_ELSE",
    "TOKEN_RANGE",
    "TOKEN_STR",

    "TOKEN_ILLEGAL",
    "TOKEN_EOF"};

#endif
