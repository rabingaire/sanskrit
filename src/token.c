#include "token.h"

Token integer_token(TokenType type, int64_t value)
{
  Token token;
  token.type = type;
  token.integer_value = value;
  return token;
}

Token string_token(TokenType type, char *value)
{
  Token token;
  token.type = type;
  token.string_value = value;
  return token;
}

// TODO: give more meaningful name
Token new_token(TokenType type, char *value)
{
  Token token;
  token.type = type;
  token.token_value = value;
  return token;
}
