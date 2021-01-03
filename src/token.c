#include "token.h"

token_T integer_token(token_type_T type, int64_t value)
{
  token_T token;
  token.type = type;
  token.integer_value = value;
  return token;
}

token_T string_token(token_type_T type, char *value)
{
  token_T token;
  token.type = type;
  token.string_value = value;
  return token;
}

// TODO: give more meaningful name
token_T new_token(token_type_T type, char *value)
{
  token_T token;
  token.type = type;
  token.token_value = value;
  return token;
}
