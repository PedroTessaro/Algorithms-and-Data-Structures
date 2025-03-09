#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFUL)

typedef struct {
  char name[MAX_NAME];
  int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;

  for (int i = 0; i < length; i++) {
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

bool hash_table_insert(person *p) {
  if (p == NULL)
    return false;

  int index = hash(p->name);

  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
      hash_table[try] = p;
      return true;
    }
  }
  return false;
}

person *hash_table_delete(char *name) {
  int index = hash(name);

  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (index + i) % TABLE_SIZE;

    if (hash_table[try] == NULL) {
      return NULL;
    }

    if (hash_table[try] == DELETED_NODE)
      continue;

    if (hash_table[try] != NULL &&
        strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
      person *temp = hash_table[try];
      hash_table[try] = DELETED_NODE;

      return temp;
    }
  }
  return NULL;
}

person *hash_table_lookup(char *name) {
  int index = hash(name);

  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (index + i) % TABLE_SIZE;

    if (hash_table[try] == NULL) {
      return false;
    }

    if (hash_table[try] == DELETED_NODE)
      continue;

    if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
      return hash_table[try];
    }
  }
  return NULL;
}

void print_table() {
  printf("---Start---\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else if (hash_table[i] == DELETED_NODE) {
      printf("\t%i\t<deleted>\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
  printf("---Finish---\n");
}

int main() {

  init_hash_table();
  print_table();

  person jacob = {.name = "Jacob", .age = 23};
  person marcus = {.name = "Marcus", .age = 21};
  person andre = {.name = "Andre", .age = 42};
  person maria = {.name = "Maria", .age = 12};

  hash_table_insert(&jacob);
  hash_table_insert(&marcus);
  hash_table_insert(&andre);
  hash_table_insert(&maria);

  print_table();

  hash_table_delete("Marcus");

  print_table();

  person *temp = hash_table_lookup("Andre");

  if (temp == NULL) {
    printf("Not found!\n");
  } else {
    printf("Found %s", temp->name);
  }
}
