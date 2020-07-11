#include "lexer.h"

Lexer* new_lexer(char* input) {
  Lexer* lex = (Lexer*)malloc(sizeof(Lexer));
  lex->input = input;
  lex->position = 0;
  lex->read_position = 1;
  lex->character = lex->input[lex->position];
  return lex;
}

char read_character(Lexer* lex) {
  lex->position = lex->read_position;
  lex->read_position++;
  lex->character = lex->input[lex->position];
  return lex->character;
}

char peek_character(Lexer* lex) {
  size_t peek_position = lex->read_position;
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

char* read_number(Lexer* lex) {
  char* ident = "";
  while(true) {
    ident = append(ident, &lex->character);
    if(!isdigit(peek_character(lex))) {
      break;
    }
    read_character(lex);
  }
  return ident;
}

void skip_whitespace(Lexer* lex) {
	while(lex->character == ' ' || lex->character == '\t' || lex->character == '\n' || lex->character == '\r') {
    read_character(lex);
	}
}

Token next_token(Lexer* lex) {
  Token token;

  skip_whitespace(lex);

  switch(lex->character) {
    case '=': {
      token = new_token(ASSIGN, "=");
      break;
    }
    case '+': {
      token = new_token(PLUS, "+");
      break;
    }
    case ';': {
      token = new_token(SEMICOLON, ";");
      break;
    }
    case '(': {
      token = new_token(LPAREN, "(");
      break;
    }
    case ')': {
      token = new_token(RPAREN, ")");
      break;
    }
    case '{': {
      token = new_token(LBRACE, "{");
      break;
    }
    case '}': {
      token = new_token(RBRACE, "}");
      break;
    }
    case ':': {
      token = new_token(COLON, ":");
      break;
    }
    case ',': {
      token = new_token(COMMA, ",");
      break;
    }
    case 0: {
      token = new_token(EOFF, "EOF");
      break;
    }
    default: {
      if(isalpha(lex->character)) {
        char* ident = read_ident(lex);

        if(!strncmp(ident, "let", 3)) {
          token = new_token(LET, ident);
          break;
        }

        if(!strncmp(ident, "int", 3)) {
          token = new_token(INT, ident);
          break;
        }

        if(!strncmp(ident, "return", 6)) {
          token = new_token(RETURN, ident);
          break;
        }

        token = new_token(IDENT, ident);
        break;
      }
      
      if(isdigit(lex->character)) {
        char* integer = read_number(lex);
        token = new_token(NUMBER, integer);
        break;
      }

      token = new_token(ILLEGAL, append("", &lex->character));
      break;
    }
  }
  read_character(lex);
  return token;
}
