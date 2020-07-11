#include "utils.h"

char* append(const char* dest, const char* source) {
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


// TODO: rewrite this with better error handling
char* read_from_file(const char* file_path) {
  FILE* f = fopen(file_path, "r");
  if(f == NULL) {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  }

  if(fseek(f, 0, SEEK_END) != 0) {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  };

  long fsize = ftell(f);
  rewind(f);

  char* string = malloc(fsize + 1);
  fread(string, 1, fsize, f);
  if(ferror(f) != 0) {
    fatalf(FILE_READ, "Can't read file: %s\n", file_path);
  }

  if(fclose(f) != 0) {
    fatalf(FILE_CLOSE, "Can't close file: %s\n", file_path);
  };

  return string;
}

void fatalf(const int exit_code, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  exit(exit_code);
  va_end(args);
}
