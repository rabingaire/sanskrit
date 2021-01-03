#ifndef SK_LEXER_H
#define SK_LEXER_H

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "utils.h"
#include "token.h"
#include "error_codes.h"

typedef struct
{
  char *input;
  size_t position;
  size_t read_position;
  char character;
} lexer_T;

lexer_T *new_lexer(char *);

token_T next_token(lexer_T *);

#endif
