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
  char* literal = "";
  while(true) {
    literal = append(literal, &lex->character);
    if(!isalpha(peek_character(lex))) {
      break;
    }
    read_character(lex);
  }
  return literal;
}

int64_t read_integer(Lexer* lex) {
  int64_t literal = 0;
  while(true) {
    literal *= 10;
    literal += lex->character - '0';
    if(!isdigit(peek_character(lex))) {
      break;
    }
    read_character(lex);
  }
  return literal;
}

char* read_string(Lexer* lex) {
  char* literal = "";
  while(true) {
    read_character(lex);
    literal = append(literal, &lex->character);
    if(!peek_character(lex) || peek_character(lex) == '"') {
      read_character(lex);
      break;
    }
  }
  return literal;
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
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(EQUAL, "==");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(ASSIGN, "=");
        }
      }
      break;
    }
    case '&': {
      switch(peek_character(lex)) {
        case '&': {
          token = new_token(AND, "&&");
          read_character(lex);
          break;
        }
        default: {
          // Single & character is illegal for now
          token = new_token(ILLEGAL, append("", &lex->character));
        }
      }
      break;
    }
    case '|': {
      switch(peek_character(lex)) {
        case '|': {
          token = new_token(OR, "||");
          read_character(lex);
          break;
        }
        default: {
          // Single | character is illegal for now
          token = new_token(ILLEGAL, append("", &lex->character));
        }
      }
      break;
    }
    case '+': {
      switch(peek_character(lex)) {
        case '+': {
          token = new_token(INCREMENT, "++");
          read_character(lex);
          break;
        }
        case '=': {
          token = new_token(PLUS_ASSIGN, "+=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(PLUS, "+");
        }
      }
      break;
    }
    case '-': {
      switch(peek_character(lex)) {
        case '-': {
          token = new_token(DECREMENT, "--");
          read_character(lex);
          break;
        }
        case '=': {
          token = new_token(MINUS_ASSIGN, "-=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(MINUS, "-");
        }
      }
      break;
    }
    case '!': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(NOT_EQUAL, "!=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(EXCLAMATION, "!");
        }
      }
      break;
    }
    case '*': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(ASTERISK_ASSIGN, "*=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(ASTERISK, "*");
        }
      }
      break;
    }
    case '/': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(SLASH_ASSIGN, "/=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(SLASH, "/");
        }
      }
      break;
    }
    case ',': {
      token = new_token(COMMA, ",");
      break;
    }
    case ';': {
      token = new_token(SEMICOLON, ";");
      break;
    }
    case ':': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(COLON_ASSIGN, ":=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(COLON, ":");
        }
      }
      break;
    }
    case '<': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(LESS_THEN_EQUAL, "<=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(LESS_THEN, "<");
        }
      }
      break;
    }
    case '>': {
      switch(peek_character(lex)) {
        case '=': {
          token = new_token(GREATER_THEN_EQUAL, ">=");
          read_character(lex);
          break;
        }
        default: {
          token = new_token(GREATER_THEN, ">");
        }
      }
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
    case '"': {
      char* literal = read_string(lex);
      token = string_token(STRING, literal);
      break;
    }
    case 0: {
      token = new_token(EOFF, "EOF");
      break;
    }
    default: {
      if(isalpha(lex->character)) {
        char* literal = read_ident(lex);

        // TODO: use string interning for comparing string
        if(!strncmp(literal, "let", 3)) {
          token = new_token(LET, literal);
          break;
        }

        if(!strncmp(literal, "int", 3)) {
          token = new_token(INT, literal);
          break;
        }

        if(!strncmp(literal, "return", 6)) {
          token = new_token(RETURN, literal);
          break;
        }

        if(!strncmp(literal, "void", 4)) {
          token = new_token(VOID, literal);
          break;
        }

        if(!strncmp(literal, "for", 3)) {
          token = new_token(FOR, literal);
          break;
        }

        if(!strncmp(literal, "true", 4)) {
          token = new_token(BOOL, literal);
          break;
        }

        if(!strncmp(literal, "false", 4)) {
          token = new_token(BOOL, literal);
          break;
        }

        if(!strncmp(literal, "if", 2)) {
          token = new_token(IF, literal);
          break;
        }

        if(!strncmp(literal, "else", 4)) {
          token = new_token(ELSE, literal);
          break;
        }

        if(!strncmp(literal, "range", 5)) {
          token = new_token(RANGE, literal);
          break;
        }

        if(!strncmp(literal, "str", 3)) {
          token = new_token(STR, literal);
          break;
        }

        token = new_token(IDENT, literal);
        break;
      }
      
      if(isdigit(lex->character)) {
        int64_t integer = read_integer(lex);
        token = integer_token(INTEGER, integer);
        break;
      }

      token = new_token(ILLEGAL, append("", &lex->character));
      break;
    }
  }
  read_character(lex);
  return token;
}
