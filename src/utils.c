#include "utils.h"

char* append(char* dest, char* source) {
  char* result = NULL;
  asprintf(&result, "%s%s", dest, source);
  return result;
}

void *buf__grow(const void *buf, size_t new_len, size_t elem_size) {
  size_t new_cap = MAX(1 + 2 * buf_cap(buf), new_len);
  size_t new_size = offsetof(BufHdr, buf) + new_cap * elem_size;
  BufHdr *new_hdr;
  if(buf) {
    new_hdr = (BufHdr *)realloc(buf__hdr(buf), new_size);
  } else {
    new_hdr = (BufHdr *)malloc(new_size);
    new_hdr->len = 0;
  }
  new_hdr->cap = new_cap;
  return new_hdr->buf;
}
