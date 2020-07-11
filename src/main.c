#include "token.h"
#include "lexer.h"
#include "utils.h"
#include "error_codes.h"

int main(int argc, char** argv) {
  char* fileName = argv[1];

  if (argc < 2 && fileName == NULL) {
    printf("no sanskrit file listed\n");
    exit(NO_SOURCE_FILE);
  }

  char* input = read_from_file(fileName);

  Lexer* lex = new_lexer(input);

  while(read_character(lex)) {
    Token token = next_token(lex);
    printf("Token type: %u \t Token literal: %s\n", token.type, token.literal);
  }

  return 0;
}
