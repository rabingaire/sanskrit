#include "token.h"
#include "lexer.h"

int main(int argc, char** argv) {
  char* input = "let a: int = (1 + 1); fn hello(a: int, b: int):int { return a + b };";

  Lexer* lex = new_lexer(input);

  while(read_character(lex)) {
    Token token = next_token(lex);
    printf("Token type: %u \t Token literal: %s\n", token.type, token.literal);
  }

  return 0;
}

