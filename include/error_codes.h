#ifndef ERROR_CODES
#define ERROR_CODES

typedef enum {
  NO_SOURCE_FILE,

  FILE_READ,
  FILE_CLOSE,
  
  INVALID_CHARACTER
} ErrorCode;

#endif
