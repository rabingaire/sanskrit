#include "token.h"
#include "lexer.h"

int main(int argc, char** argv) {
  char* input = "let a = (1 + 1); fn hello(){};";

  size_t token_counter = 0;
  Token tokens[100];

  Lexer* lex = new_lexer(input);

  while(read_character(lex)) {
    switch(lex->character) {
      case ' ': {
        // Skip whitespace
        break;
      }
      case '=': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(ASSIGN, "=");
        token_counter++;
        break;
      }
      case '+': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(PLUS, "+");
        token_counter++;
        break;
      }
      case ';': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(SEMICOLON, ";");
        token_counter++;
        break;
      }
      case '(': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(LPAREN, "(");
        token_counter++;
        break;
      }
      case ')': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(RPAREN, ")");
        token_counter++;
        break;
      }
      case '{': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(LBRACE, "{");
        token_counter++;
        break;
      }
      case '}': {
        //tokens[lex->position] = token;
        tokens[token_counter] = new_token(RBRACE, "}");
        token_counter++;
        break;
      }
      default: {
        if(isalpha(lex->character)) {
          char* ident = read_ident(lex);
          tokens[token_counter] = new_token(IDENT, ident);
          token_counter++;
        } else if(isdigit(lex->character)) {
          int integer = read_number(lex);
          char* literal = NULL;
          asprintf(&literal, "%d", integer);
          tokens[token_counter] = new_token(INT, literal);
          token_counter++;
        } else {
          printf("<INVALID> char %c, at %zu\n", lex->character, lex->position);
        }
      }
    }
  }
  
  for(size_t i = 0; i < token_counter; i++) {
    printf("Token type: %u \t Token literal: %s\n", tokens[i].type, tokens[i].literal);
  }

  return 0;
}

