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

void skip_whitespace(Lexer* lex) {
	while(lex->character == ' ' || lex->character == '\t' || lex->character == '\n' || lex->character == '\r') {
		read_character(lex);
	}
}

Token next_token(Lexer* lex) {
  skip_whitespace(lex);

  switch(lex->character) {
    case '=': {
      return new_token(ASSIGN, "=");
    }
    case '+': {
      return new_token(PLUS, "+");
    }
    case ';': {
      return new_token(SEMICOLON, ";");
    }
    case '(': {
      return new_token(LPAREN, "(");
    }
    case ')': {
      return new_token(RPAREN, ")");
    }
    case '{': {
      return new_token(LBRACE, "{");
    }
    case '}': {
      return new_token(RBRACE, "}");
    }
    case ':': {
      return new_token(COLON, ":");
    }
    case ',': {
      return new_token(COMMA, ",");
    }
    default: {
      if(isalpha(lex->character)) {
        char* ident = read_ident(lex);

        if(!strncmp(ident, "let", 3)) {
          return new_token(LET, ident);
        }

        if(!strncmp(ident, "int", 3)) {
          return new_token(INT, ident);
        }

        if(!strncmp(ident, "return", 6)) {
          return new_token(RETURN, ident);
        }

        return new_token(IDENT, ident);
      }
      
      if(isdigit(lex->character)) {
        int integer = read_number(lex);
        char* literal = NULL;
        asprintf(&literal, "%d", integer);
        return new_token(NUMBER, literal);
      }
      
      printf("<INVALID> char %c, at %zu\n", lex->character, lex->position);
      exit(1);
    }
  }
}
