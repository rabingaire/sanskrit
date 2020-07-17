#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "token.h"
#include "error_codes.h"

char* append(const char*, const char*);
char* read_from_file(const char*);
void fatalf(const int, const char*, ...);
void printToken(Token);

#endif
