#ifndef SK_UTILS_H
#define SK_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "token.h"
#include "error_codes.h"

char *append(const char *, const char *);

char *read_from_file(const char *);

void fatalf(const int, const char *, ...);

void printToken(token_T);

#endif
