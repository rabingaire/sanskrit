#ifndef TOKEN
#define TOKEN

#include <stdint.h>

#include "token_type.h"

typedef struct {
  TokenType type;
  // TODO: refactor
  // Tagged Union: this will be set 0, 1, 2, ... 
  // as the value in union is set
  // eg: if integer_value is set set_union will contain 0
  // eg: if string_value is set set_union will contain 1
  // order of occurrence of union fields sets set_union
  unsigned char set_union; 
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
