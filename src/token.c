#include "token.h"

Token new_token(TokenType type, char* literal) {
  Token token;
  token.type = type;
  token.literal = literal;
  return token;
}
