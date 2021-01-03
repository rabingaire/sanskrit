#include "token.h"
#include "lexer.h"
#include "utils.h"

int main(int argc, char **argv)
{
  char *fileName = argv[1];

  if (argc < 2 && fileName == NULL)
  {
    fatalf(NO_SOURCE_FILE, "no sanskrit file listed\n");
  }

  char *input = read_from_file(fileName);

  lexer_T *lex = new_lexer(input);

  while (true)
  {
    token_T token = next_token(lex);
    printToken(token);
    if (token.type == TOKEN_EOF)
    {
      break;
    }
  }

  return 0;
}
