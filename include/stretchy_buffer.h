
#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) >= (y) ? (x) : (y))

// Public API
#define buf_len(b) ((b) ? buf__raw(b)[0]: 0)
#define buf_cap(b) ((b) ? buf__raw(b)[1]: 0)
#define buf_push(b, x) (buf__fit(b, 1), b[buf_len(b)] = x, buf__raw(b)[0]++)
#define buf_free(b) ((b) ? free(buf__raw(b)): 0)

// Private API
#define buf__raw(b) ((b) ? ((int *) (void *)(b)) - 2: 0)
#define buf__fits(b, n) (buf_len(b) + (n) <= buf_cap(b))
#define buf__fit(b, n) (buf__fits(b , n) ? 0 : ((b) = buf__grow((b), buf_len(b) + (n), sizeof(*(b)))))


void* buf__grow(const void* buf, int new_len, int elem_size) {
  int new_cap = max(1 + 2 * buf_cap(buf), new_len);
  int new_size = sizeof(int) * 2 + new_cap * elem_size;
  int* new_buf;
  if(buf) {
    new_buf = realloc(buf__raw(buf), new_size);
  } else {
    new_buf = malloc(new_size);
    new_buf[0] = 0;
  }
  new_buf[1] = new_cap;
  return new_buf + 2;
}
