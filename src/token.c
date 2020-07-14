#include "token.h"

Token integer_token(TokenType type, int64_t value) {
  Token token;
  token.type = type;
  token.set_union = 0;
  token.integer_value = value;
  return token;
}

Token string_token(TokenType type, char* value) {
  Token token;
  token.type = type;
  token.set_union = 1;
  token.string_value = value;
  return token;
}

// TODO: give more meaningful name
Token new_token(TokenType type, char* value) {
  Token token;
  token.type = type;
  token.set_union = 2;
  token.token_value = value;
  return token;
}
