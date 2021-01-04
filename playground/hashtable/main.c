#include "hashtable.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
  hash_table_T *hash_table = init_hash(2);

  hash_insert(hash_table, "rabin", 10);
  hash_insert(hash_table, "rab", 20);

  printf("%d\n", (int)hash_get(hash_table, "rabin"));
  printf("%d\n", (int)hash_get(hash_table, "rab"));

  printf("%d\n", (int)hash_delete(hash_table, "rab"));
  if (hash_get(hash_table, "rab") == NULL)
  {
    printf("Value is null\n");
  }
  return 0;
}
