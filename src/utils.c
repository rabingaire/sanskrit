#include "utils.h"

char* append(char* dest, char* source) {
  char* result = NULL;
  asprintf(&result, "%s%s", dest, source);
  return result;
}
