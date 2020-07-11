#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "error_codes.h"

char* append(char*, char*);
char* read_from_file(char*);

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

typedef struct {
  size_t len;
  size_t cap;
  char buf[0];
} BufHdr;

// Private API
#define buf__hdr(b) ((BufHdr *)((char *)b - offsetof(BufHdr, buf)))
#define buf__fits(b, n) (buf_len(b) + (n) <= buf_cap(b))
#define buf__fit(b, n) (buf__fits(b , n) ? 0 : ((b) = buf__grow((b), buf_len(b) + (n), sizeof(*(b)))))

void *buf__grow(const void*, size_t, size_t);

// Public API
#define buf_len(b) ((b) ? buf__hdr(b)->len: 0)
#define buf_cap(b) ((b) ? buf__hdr(b)->cap: 0)
#define buf_push(b, x) (buf__fit(b, 1), b[buf_len(b)] = x, buf__hdr(b)->len++)
#define buf_free(b) ((b) ? free(buf__hdr(b)): 0)

#endif
