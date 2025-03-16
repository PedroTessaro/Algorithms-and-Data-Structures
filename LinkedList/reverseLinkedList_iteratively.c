#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} node_t;

void print_list(node_t *head) {
  node_t *temp = head;

  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

void insert(node_t **head, int value) {
  node_t *temp = (node_t *)malloc(sizeof(node_t));
  temp->value = value;
  temp->next = NULL;

  if (*head == NULL)
    *head = temp;
  else {
    node_t *temp1 = *head;
    while (temp1->next != NULL)
      temp1 = temp1->next;
    temp1->next = temp;
  }
}

void Reverse(node_t **head) {
  node_t *current, *prev, *next;
  current = *head;
  prev = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

int main() {
  node_t *head = NULL;

  insert(&head, 2);
  insert(&head, 4);
  insert(&head, 6);
  insert(&head, 8);
  print_list(head);
  Reverse(&head);
  print_list(head);
}
