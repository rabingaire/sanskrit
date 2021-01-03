#include "utils.h"

// TODO: look for more better way to append two strings
char *append(const char *dest, const char *source)
{
  char *result = NULL;
  asprintf(&result, "%s%s", dest, source);
  return result;
}

// TODO: rewrite this with better error handling
char *read_from_file(const char *file_path)
{
  FILE *f = fopen(file_path, "r");
  if (f == NULL)
  {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  }

  if (fseek(f, 0, SEEK_END) != 0)
  {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  };

  long fsize = ftell(f);
  rewind(f);

  char *string = malloc(fsize + 1);
  fread(string, 1, fsize, f);
  if (ferror(f) != 0)
  {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  }

  if (fclose(f) != 0)
  {
    fatalf(FILE_CLOSE, "Can't close file: %s\n", file_path);
  };

  return string;
}

void fatalf(const int exit_code, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  exit(exit_code);
  va_end(args);
}

void printToken(token_T token)
{
  switch (token.type)
  {
  case TOKEN_INTEGER:
  {
    printf("Token type: %u \t Token literal: %lld\n", token.type, token.integer_value);
    break;
  }
  case TOKEN_STRING:
  {
    printf("Token type: %u \t Token literal: %s\n", token.type, token.string_value);
    break;
  }
  default:
  {
    printf("Token type: %u \t Token literal: %s\n", token.type, token.token_value);
    break;
  }
  }
}
