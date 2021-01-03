#include "lexer.h"

static inline char read_next_character(lexer_T *);
static inline char peek_character(lexer_T *);
static char *read_ident(lexer_T *);
static int64_t read_integer(lexer_T *);
static char *read_string(lexer_T *);
static void skip_whitespace(lexer_T *);

lexer_T *new_lexer(char *input)
{
  lexer_T *lex = (lexer_T *)malloc(sizeof(lexer_T));
  lex->input = input;
  lex->position = 0;
  lex->read_position = 1;
  lex->character = lex->input[lex->position];
  return lex;
}

static inline char read_next_character(lexer_T *lex)
{
  lex->position = lex->read_position;
  lex->read_position++;
  lex->character = lex->input[lex->position];
  return lex->character;
}

static inline char peek_character(lexer_T *lex)
{
  size_t peek_position = lex->read_position;
  return lex->input[peek_position];
}

static char *read_ident(lexer_T *lex)
{
  char *literal = "";
  while (true)
  {
    literal = append(literal, &lex->character);
    if (!isalpha(peek_character(lex)))
    {
      break;
    }
    read_next_character(lex);
  }
  return literal;
}

static int64_t read_integer(lexer_T *lex)
{
  int64_t literal = 0;
  while (true)
  {
    literal *= 10;
    literal += lex->character - '0';
    if (!isdigit(peek_character(lex)))
    {
      break;
    }
    read_next_character(lex);
  }
  return literal;
}

static char *read_string(lexer_T *lex)
{
  char *literal = "";
  while (true)
  {
    read_next_character(lex);
    literal = append(literal, &lex->character);
    if (!peek_character(lex) || peek_character(lex) == '"')
    {
      read_next_character(lex);
      break;
    }
  }
  return literal;
}

static void skip_whitespace(lexer_T *lex)
{
  while (lex->character == ' ' || lex->character == '\t' || lex->character == '\n' || lex->character == '\r')
  {
    read_next_character(lex);
  }
}

token_T next_token(lexer_T *lex)
{
  token_T token;

  skip_whitespace(lex);

  switch (lex->character)
  {
  case '=':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_EQUAL, "==");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_ASSIGN, "=");
    }
    }
    break;
  }
  case '&':
  {
    switch (peek_character(lex))
    {
    case '&':
    {
      token = new_token(TOKEN_AND, "&&");
      read_next_character(lex);
      break;
    }
    default:
    {
      // Single & character is illegal for now
      token = new_token(TOKEN_ILLEGAL, append("", &lex->character));
    }
    }
    break;
  }
  case '|':
  {
    switch (peek_character(lex))
    {
    case '|':
    {
      token = new_token(TOKEN_OR, "||");
      read_next_character(lex);
      break;
    }
    default:
    {
      // Single | character is illegal for now
      token = new_token(TOKEN_ILLEGAL, append("", &lex->character));
    }
    }
    break;
  }
  case '+':
  {
    switch (peek_character(lex))
    {
    case '+':
    {
      token = new_token(TOKEN_INCREMENT, "++");
      read_next_character(lex);
      break;
    }
    case '=':
    {
      token = new_token(TOKEN_PLUS_ASSIGN, "+=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_PLUS, "+");
    }
    }
    break;
  }
  case '-':
  {
    switch (peek_character(lex))
    {
    case '-':
    {
      token = new_token(TOKEN_DECREMENT, "--");
      read_next_character(lex);
      break;
    }
    case '=':
    {
      token = new_token(TOKEN_MINUS_ASSIGN, "-=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_MINUS, "-");
    }
    }
    break;
  }
  case '!':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_NOT_EQUAL, "!=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_EXCLAMATION, "!");
    }
    }
    break;
  }
  case '*':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_ASTERISK_ASSIGN, "*=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_ASTERISK, "*");
    }
    }
    break;
  }
  case '/':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_SLASH_ASSIGN, "/=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_SLASH, "/");
    }
    }
    break;
  }
  case ',':
  {
    token = new_token(TOKEN_COMMA, ",");
    break;
  }
  case ';':
  {
    token = new_token(TOKEN_SEMICOLON, ";");
    break;
  }
  case ':':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_COLON_ASSIGN, ":=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_COLON, ":");
    }
    }
    break;
  }
  case '<':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_LESS_THEN_EQUAL, "<=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_LESS_THEN, "<");
    }
    }
    break;
  }
  case '>':
  {
    switch (peek_character(lex))
    {
    case '=':
    {
      token = new_token(TOKEN_GREATER_THEN_EQUAL, ">=");
      read_next_character(lex);
      break;
    }
    default:
    {
      token = new_token(TOKEN_GREATER_THEN, ">");
    }
    }
    break;
  }
  case '(':
  {
    token = new_token(TOKEN_LPAREN, "(");
    break;
  }
  case ')':
  {
    token = new_token(TOKEN_RPAREN, ")");
    break;
  }
  case '{':
  {
    token = new_token(TOKEN_LBRACE, "{");
    break;
  }
  case '}':
  {
    token = new_token(TOKEN_RBRACE, "}");
    break;
  }
  case '"':
  {
    char *literal = read_string(lex);
    token = string_token(TOKEN_STRING, literal);
    break;
  }
  case 0:
  {
    token = new_token(TOKEN_EOF, "EOF");
    break;
  }
  default:
  {
    if (isalpha(lex->character))
    {
      char *literal = read_ident(lex);

      // TODO: use string interning for comparing string
      if (!strncmp(literal, "let", 3))
      {
        token = new_token(TOKEN_LET, literal);
        break;
      }

      if (!strncmp(literal, "int", 3))
      {
        token = new_token(TOKEN_INT, literal);
        break;
      }

      if (!strncmp(literal, "return", 6))
      {
        token = new_token(TOKEN_RETURN, literal);
        break;
      }

      if (!strncmp(literal, "void", 4))
      {
        token = new_token(TOKEN_VOID, literal);
        break;
      }

      if (!strncmp(literal, "for", 3))
      {
        token = new_token(TOKEN_FOR, literal);
        break;
      }

      if (!strncmp(literal, "true", 4))
      {
        token = new_token(TOKEN_BOOL, literal);
        break;
      }

      if (!strncmp(literal, "false", 4))
      {
        token = new_token(TOKEN_BOOL, literal);
        break;
      }

      if (!strncmp(literal, "if", 2))
      {
        token = new_token(TOKEN_IF, literal);
        break;
      }

      if (!strncmp(literal, "else", 4))
      {
        token = new_token(TOKEN_ELSE, literal);
        break;
      }

      if (!strncmp(literal, "range", 5))
      {
        token = new_token(TOKEN_RANGE, literal);
        break;
      }

      if (!strncmp(literal, "str", 3))
      {
        token = new_token(TOKEN_STR, literal);
        break;
      }

      token = new_token(TOKEN_IDENT, literal);
      break;
    }

    if (isdigit(lex->character))
    {
      int64_t integer = read_integer(lex);
      token = integer_token(TOKEN_INTEGER, integer);
      break;
    }

    token = new_token(TOKEN_ILLEGAL, append("", &lex->character));
    break;
  }
  }
  read_next_character(lex);
  return token;
}
