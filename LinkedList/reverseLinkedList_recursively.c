#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} node_t;

void print_list(node_t *node) {
  if (node == NULL)
    return;
  printf("%d ", node->value);
  print_list(node->next);
}

void reverse_print(node_t *node) {
  if (node == NULL)
    return;
  reverse_print(node->next);
  printf("%d ", node->value);
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

void recursive_reverse(node_t *node, node_t **head) {
  if (node->next == NULL) {
    *head = node;
    return;
  }
  recursive_reverse(node->next, head);
  node->next->next = node;
  node->next = NULL;
}

int main() {
  node_t *head = NULL;
  insert(&head, 2);
  insert(&head, 4);
  insert(&head, 6);
  insert(&head, 5);
  print_list(head);
  printf("\n");
  reverse_print(head);
  printf("\n");
  recursive_reverse(head, &head);
  print_list(head);
}
