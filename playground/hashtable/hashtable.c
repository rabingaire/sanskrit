#include "hashtable.h"
#include <stdio.h>

hash_table_T *init_hash(size_t capacity)
{
  hash_table_T *hash_table = calloc(1, sizeof(struct HASH_TABLE));
  hash_table->elements = calloc(capacity, sizeof(struct HASH_ELEMENT));
  hash_table->capacity = capacity;
  return hash_table;
}

void *hash_get(hash_table_T *table, char *key)
{
  size_t hash_value = _hash_function(table, key);
  hash_element_T *element = table->elements[hash_value];
  if (element)
  {
    return element->value;
  }
  return NULL;
}

// Private function

// TODO: I am thinking of doing linear probing to handle collision.
void _hash_insert(hash_table_T *table, char *key, void *value)
{
  hash_element_T *element = calloc(1, sizeof(struct HASH_ELEMENT));
  element->key = key;
  element->value = value;

  size_t hash_value = _hash_function(table, key);

  table->elements[hash_value] = element;
}

size_t _hash_function(hash_table_T *table, char *key)
{
  size_t number = 1;
  for (size_t i = 0; i < strlen(key); i++)
  {
    number += key[i];
  }
  return number % table->capacity;
}
