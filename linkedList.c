#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};
typedef struct node node_t;

node_t *createNode(int value) {
  node_t *result = malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;

  return result;
}

void insertAtHead(node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  *head = node_to_insert;
}

void insertAfter(node_t *nodeBefore, node_t *newNode) {
  newNode->next = nodeBefore->next;
  nodeBefore->next = newNode;
}

node_t *findNode(node_t *head, int value) {
  node_t *temp = head;

  while (temp != NULL) {
    if (temp->value == value)
      return temp;
    temp = temp->next;
  }

  return NULL;
}

void printNodes(node_t *head) {
  node_t *temp = head;

  while (temp != NULL) {
    printf("%d - ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  node_t *head = NULL;
  node_t *temp;

  for (int i = 0; i < 25; i++) {
    temp = createNode(i);
    insertAtHead(&head, temp);
  }

  temp = findNode(head, 22);
  insertAfter(temp, createNode(42));

  printNodes(head);

  return 0;
}
