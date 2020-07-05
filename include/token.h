#ifndef TOKEN
#define TOKEN

#include "token_type.h"

typedef struct {
  TokenType type;
  char* literal;
} Token;

Token new_token(TokenType, char*);

#endif
