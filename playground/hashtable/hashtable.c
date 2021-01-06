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
  void *value = NULL;

  hash_element_T *element = _hash_get_element(table, key);
  if (element)
  {
    value = element->value;
  }

  return value;
}

void *hash_delete(hash_table_T *table, char *key)
{
  void *value = NULL;

  hash_element_T *element = _hash_get_element(table, key);
  if (element)
  {
    element->deleted = 1;
    value = element->value;
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

  void *inserted = _hash_insert_element(table, element);
  if (inserted == NULL)
  {
    _resize_hash_table(table);
    inserted = _hash_insert_element(table, element);
  }

  return inserted;
}

void *_hash_insert_element(hash_table_T *table, hash_element_T *element)
{
  void *value = NULL;

  size_t hash_value = _hash_function(table, element->key);

  for (int count = 0; count < table->capacity; count++)
  {
    int index = (hash_value + count * count) % table->capacity;
    hash_element_T *elm = table->elements[index];

    if (!elm || (elm && elm->deleted && elm->key == element->key))
    {
      table->elements[index] = element;
      value = element->value;
      break;
    }
  }

  return value;
}

hash_element_T *_hash_get_element(hash_table_T *table, char *key)
{
  size_t hash_value = _hash_function(table, key);

  hash_element_T *element = NULL;

  for (int count = 0; count < table->capacity; count++)
  {
    int index = (hash_value + count * count) % table->capacity;
    hash_element_T *elm = table->elements[index];

    if (elm && !elm->deleted && elm->key == key)
    {
      element = elm;
      break;
    }
  }

  return element;
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

void _resize_hash_table(hash_table_T *table)
{
  hash_table_T *new_hash_table = init_hash(table->capacity * 2);

  for (int index = 0; index < table->capacity; index++)
  {
    hash_element_T *element = table->elements[index];
    if (element)
    {
      _hash_insert_element(new_hash_table, element);
    }
  }

  table->elements = new_hash_table->elements;
  table->capacity = new_hash_table->capacity;

  free(new_hash_table);
}
