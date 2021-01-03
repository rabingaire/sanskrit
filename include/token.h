#ifndef SK_TOKEN_H
#define SK_TOKEN_H

#include <stdint.h>

#include "token_type.h"

typedef struct
{
  token_type_T type;
  union
  {
    int64_t integer_value;
    char *string_value;
    char *token_value;
  };
} token_T;

token_T integer_token(token_type_T, int64_t);

token_T string_token(token_type_T, char *);

token_T new_token(token_type_T, char *);

#endif
