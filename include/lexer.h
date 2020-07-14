#ifndef LEXER
#define LEXER

#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "utils.h"
#include "token.h"
#include "error_codes.h"

typedef struct {
  char* input;
  size_t position;
  size_t read_position;
  char character;
} Lexer;

Lexer* new_lexer(char*);

char read_character(Lexer*);

char peek_character(Lexer*);

char* read_ident(Lexer*);

int64_t read_integer(Lexer*);

void skip_whitespace(Lexer*);

Token next_token(Lexer*);

#endif
