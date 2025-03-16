#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
} node_t;

node_t *create_node(int value) {
  node_t *newnode = (node_t *)malloc(sizeof(node_t));
  newnode->value = value;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

void insert_at_head(node_t **head, int value) {
  node_t *temp = create_node(value);
  if (*head == NULL) {
    *head = temp;
  } else {
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
  }
}

void insert_at_tail(node_t *head, int value) {
  node_t *count = head;
  while (count->next != NULL) {
    count = count->next;
  }
  node_t *temp = create_node(value);
  count->next = temp;
  temp->prev = count;
}

void print_list(node_t *head) {
  node_t *temp = head;

  printf("Forward: ");
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

void reverse_print_list(node_t *head) {
  node_t *temp = head;
  if (temp == NULL)
    return;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  printf("Reverse: ");
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->prev;
  }
  printf("\n");
}

int main() {
  node_t *head = NULL;
  insert_at_head(&head, 2);
  print_list(head);
  reverse_print_list(head);
  insert_at_head(&head, 4);
  print_list(head);
  reverse_print_list(head);
  insert_at_head(&head, 5);
  print_list(head);
  reverse_print_list(head);
  printf("\n");
  insert_at_tail(head, 20);
  print_list(head);
  return 0;
}
