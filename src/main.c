#include "token.h"
#include "lexer.h"
#include "utils.h"
#include "error_codes.h"

int main(int argc, char** argv) {
  char* fileName = argv[1];

  if (argc < 2 && fileName == NULL) {
    fatalf(NO_SOURCE_FILE, "no sanskrit file listed\n"); 
  }

  char* input = read_from_file(fileName);

  Lexer* lex = new_lexer(input);

  while(true) {
    Token token = next_token(lex);
    printf("Token type: %u \t Token literal: %s\n", token.type, token.literal);
    if(token.type == EOFF) {
      break;
    } 
  }

  return 0;
}
