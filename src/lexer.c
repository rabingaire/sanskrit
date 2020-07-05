#include "lexer.h"

Lexer* new_lexer(char* input) {
  Lexer* lex = (Lexer*)malloc(sizeof(Lexer));
  lex->input = input;
  lex->position = 0;
  lex->read_position = 0;
  lex->character = 0;
  return lex;
}

char read_character(Lexer* lex) {
  if(lex->read_position >= strlen(lex->input)) {
    lex->character = 0;
  }
  lex->character = lex->input[lex->read_position];
  lex->position = lex->read_position;
  lex->read_position++;
  return lex->character;
}

char peek_character(Lexer* lex) {
  size_t peek_position = lex->read_position;
  if(peek_position >= strlen(lex->input)) {
    return 0;
  }
  return lex->input[peek_position];
}

char* read_ident(Lexer* lex) {
  char* ident = "";
  while(true) {
    ident = append(ident, &lex->character);
    if(!isalpha(peek_character(lex))) {
      break;
    }
    read_character(lex);
  }
  return ident;
}

int read_number(Lexer* lex) {
  int integer = 0;
  while(true) {
    integer *= 10;
    integer += lex->character - '0';
    if(!isdigit(peek_character(lex))) {
      break;
    }
    read_character(lex);
  }
  return integer;
}
