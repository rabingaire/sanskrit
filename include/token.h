#ifndef TOKEN
#define TOKEN

#include <stdint.h>

#include "token_type.h"

typedef struct {
  TokenType type;
  union {
    int64_t integer_value;
    char* string_value;
    char* token_value;
  };
} Token;

Token integer_token(TokenType, int64_t);

Token string_token(TokenType, char*);

Token new_token(TokenType, char*);

#endif
