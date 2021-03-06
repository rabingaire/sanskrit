#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>

typedef struct HASH_ELEMENT
{
  char *key;
  void *value;
  int deleted;
} hash_element_T;

typedef struct HASH_TABLE
{
  struct HASH_ELEMENT **elements;
  size_t capacity;
} hash_table_T;

// Public functions

hash_table_T *init_hash(size_t capacity);

#define hash_insert(table, key, value) \
  _hash_insert((table), (key), (void *)(value))

void *hash_get(hash_table_T *table, char *key);

void *hash_delete(hash_table_T *table, char *key);

// Private functions
void *_hash_insert(hash_table_T *table, char *key, void *value);

void *_hash_insert_element(hash_table_T *table, hash_element_T *element);

hash_element_T *_hash_get_element(hash_table_T *table, char *key);

size_t _hash_function(hash_table_T *table, char *key);

void _resize_hash_table(hash_table_T *table);

#endif
