#include "hashtable.h"

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

  void *value = NULL;

  for (int count = 0; count < table->capacity; count++)
  {
    int index = (hash_value + count * count) % table->capacity;
    hash_element_T *element = table->elements[index];

    if (element && !element->deleted && element->key == key)
    {
      value = element->value;
      break;
    }
  }

  return value;
}

void *hash_delete(hash_table_T *table, char *key)
{
  size_t hash_value = _hash_function(table, key);

  void *value = NULL;

  for (int count = 0; count < table->capacity; count++)
  {
    int index = (hash_value + count * count) % table->capacity;
    hash_element_T *element = table->elements[index];

    if (element && !element->deleted && element->key == key)
    {
      element->deleted = 1;
      value = element->value;
      break;
    }
  }

  return value;
}

// Private function

void *_hash_insert(hash_table_T *table, char *key, void *value)
{
  hash_element_T *element = calloc(1, sizeof(struct HASH_ELEMENT));
  element->key = key;
  element->value = value;
  element->deleted = 0;

  void *inserted = NULL;

  size_t hash_value = _hash_function(table, key);

  for (int count = 0; count < table->capacity; count++)
  {
    int index = (hash_value + count * count) % table->capacity;
    hash_element_T *elm = table->elements[index];

    if (!elm || (elm && elm->deleted && elm->key == key))
    {
      table->elements[index] = element;
      inserted = value;
      break;
    }
  }

  return inserted;
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
