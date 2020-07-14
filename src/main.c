#include "token.h"
#include "lexer.h"
#include "utils.h"
#include "error_codes.h"

void printToken(Token token) {
  switch(token.set_union) {
    case 0: {
      printf("Token type: %u \t Token literal: %lld\n", token.type, token.integer_value);
      break;
    }
    case 1: {
      printf("Token type: %u \t Token literal: %s\n", token.type, token.string_value);
      break;
    }
    case 2: {
      printf("Token type: %u \t Token literal: %s\n", token.type, token.token_value);
      break;
    }
    default: {
      printf("\n");
      break;
    }
  }
}

int main(int argc, char** argv) {
  char* fileName = argv[1];

  if (argc < 2 && fileName == NULL) {
    fatalf(NO_SOURCE_FILE, "no sanskrit file listed\n"); 
  }

  char* input = read_from_file(fileName);

  Lexer* lex = new_lexer(input);

  while(true) {
    Token token = next_token(lex);
    printToken(token);
    if(token.type == EOFF) {
      break;
    } 
  }

  return 0;
}
