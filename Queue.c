#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct {
  node *head;
  node *tail;
} queue;

void init_queue(queue *q) {
  q->head = NULL;
  q->tail = NULL;
}

bool enqueue(queue *q, int value) {
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL)
    return false;

  newnode->value = value;
  newnode->next = NULL;
  if (q->tail != NULL) {
    q->tail->next = newnode;
  }
  q->tail = newnode;

  if (q->head == NULL) {
    q->head = newnode;
  }
  return true;
}

int dequeue(queue *q) {
  if (q->head == NULL)
    return QUEUE_EMPTY;

  node *temp = q->head;
  int result = temp->value;
  q->head = q->head->next;

  if (q->head == NULL) {
    q->tail = NULL;
  }
  free(temp);
  return result;
}

int main() {
  queue q1, q2, q3;
  init_queue(&q1);
  init_queue(&q2);
  init_queue(&q3);

  enqueue(&q1, 56);
  enqueue(&q2, 60);
  enqueue(&q2, 49);
  enqueue(&q3, 63);
  enqueue(&q3, 30);
  enqueue(&q1, 90);

  printf("oi");

  int t;
  while ((t = dequeue(&q2)) != QUEUE_EMPTY) {
    printf("t = %d\n", t);
  }

  return 0;
}
