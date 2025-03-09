#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person {
  char name[MAX_NAME];
  int age;
  struct person *next;
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
  p->next = hash_table[index];
  hash_table[index] = p;

  return true;
}

person *hash_table_delete(char *name) {
  int index = hash(name);
  person *temp = hash_table[index];
  person *prev = NULL;

  while (temp != NULL && strncmp(temp->name, name, TABLE_SIZE) != 0) {
    prev = temp;
    temp = temp->next;
  }
  if (temp != NULL) {
    return NULL;
  }
  if (prev == NULL) {
    // deleting the head
    hash_table[index] = temp->next;
  } else {
    prev->next = temp->next;
  }
  return temp;
}

person *hash_table_lookup(char *name) {
  int index = hash(name);
  person *temp = hash_table[index];

  while (temp != NULL && strncmp(temp->name, name, TABLE_SIZE) != 0) {
    temp = temp->next;
  }
  return temp;
}

void print_table() {
  printf("---Start---\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t ", i);
      person *temp = hash_table[i];
      while (temp != NULL) {
        printf("%s - ", temp->name);
        temp = temp->next;
      }
      printf("\n");
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
  person mario = {.name = "Mario", .age = 32};
  person calos = {.name = "Calos", .age = 34};
  person mestre = {.name = "Mestre", .age = 65};
  person cheque = {.name = "Cheque", .age = 22};
  person bira = {.name = "Bira", .age = 90};

  hash_table_insert(&jacob);
  hash_table_insert(&marcus);
  hash_table_insert(&andre);
  hash_table_insert(&maria);
  hash_table_insert(&mario);
  hash_table_insert(&calos);
  hash_table_insert(&mestre);
  hash_table_insert(&cheque);
  hash_table_insert(&bira);

  print_table();

  person *temp = hash_table_lookup("Andre");

  if (temp == NULL) {
    printf("Not found!\n");
  } else {
    printf("Found %s", temp->name);
  }
}
