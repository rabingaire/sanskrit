#include "hashtable.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
  hash_table_T *hash_table = init_hash(2);

  printf("%d\n", (int)hash_insert(hash_table, "rat", 10));
  printf("%d\n", (int)hash_insert(hash_table, "cat", 20));
  printf("%d\n", (int)hash_insert(hash_table, "Cat", 30));

  printf("%d\n", (int)hash_get(hash_table, "rat"));
  printf("%d\n", (int)hash_get(hash_table, "cat"));

  printf("%d\n", (int)hash_delete(hash_table, "cat"));
  if (hash_get(hash_table, "cat") == NULL)
  {
    printf("Value is null\n");
  }
  return 0;
}
