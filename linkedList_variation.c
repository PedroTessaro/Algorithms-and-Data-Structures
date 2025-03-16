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

node_t *create_node(int value) {
  node_t *result = (node_t *)malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;
  return result;
}

void insert_at_head(node_t **head, node_t *temp) {
  temp->next = *head;
  (*head) = temp;
}

node_t *insert_after(node_t *head, int number_to_insert, int number_before) {
  node_t *count = head;

  while (count != NULL) {
    if (count->value == number_before) {
      node_t *temp = (node_t *)malloc(sizeof(node_t));
      temp->value = number_to_insert;
      temp->next = count->next;
      count->next = temp;
      return temp;
    }
    count = count->next;
  }

  return NULL;
}

void delete_value(node_t **head, int value) {
  node_t *temp = *head;
  int count = 0;

  while (temp != NULL) {
    if (count == 0 && temp->value == value) {
      (*head) = temp->next;
      free(temp);
      return;
    }
    if (temp->next != NULL && temp->next->value == value) {
      node_t *removed = temp->next;
      temp->next = removed->next;
      free(removed);

      return;
    }
    temp = temp->next;
    count++;
  }
}

int main() {
  node_t *head = NULL;
  node_t *temp = NULL;

  int num, num2, num3;

  printf("Selecione quantos números para entrar na lista: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    temp = create_node(i);
    insert_at_head(&head, temp);
  }

  print_list(head);

  printf("O que vc quer inserir? ");
  scanf("%d", &num2);
  printf("\nDepois de que número? ");
  scanf("%d", &num3);

  temp = insert_after(head, num2, num3);

  if (temp == NULL) {
    printf("O valor selecionado não existe!\n");
  } else {
    print_list(head);
  }

  num2 = 0;
  num3 = 0;

  printf("Qual valor você deseja excluir? ");
  scanf("%d", &num2);

  delete_value(&head, num2);

  print_list(head);
}
