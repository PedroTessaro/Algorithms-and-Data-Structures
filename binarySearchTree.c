#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int value;
  struct treenode *left;
  struct treenode *right;
} treenode;

treenode *create_node(int value) {
  treenode *result = malloc(sizeof(treenode));

  if (result != NULL) {
    result->left = NULL;
    result->right = NULL;
    result->value = value;
  }
  return result;
}

void print_tabs(int numtabs) {
  for (int i = 0; i < numtabs; i++) {
    printf("\t");
  }
}

void printtree_rec(treenode *root, int level) {
  if (root == NULL) {
    print_tabs(level);
    printf("-----<empty>-----\n");
    return;
  }
  print_tabs(level);
  printf("value = %d\n", root->value);
  print_tabs(level);
  printf("left\n");

  printtree_rec(root->left, level + 1);
  print_tabs(level);
  printf("right\n");

  printtree_rec(root->right, level + 1);
  print_tabs(level);
  printf("done\n");
}

void print_tree(treenode *root) { printtree_rec(root, 0); }

bool insert_number(treenode **rootptr, int value) {
  treenode *root = *rootptr;

  if (*rootptr == NULL) {
    // Empty tree
    (*rootptr) = create_node(value);
    return true;
  }
  if (value == root->value) {
    // Do nothing
    return false;
  }
  if (value < root->value) {
    return insert_number(&(root->left), value);
  } else {
    return insert_number(&(root->right), value);
  }
}

bool find_number(treenode *root, int value) {
  if (root == NULL) {
    return false;
  }
  if (root->value == value) {
    return true;
  }
  if (value < root->value) {
    return find_number(root->left, value);
  } else {
    return find_number(root->right, value);
  }
}

int main() {
  treenode *root = NULL;

  insert_number(&root, 16);
  insert_number(&root, 11);
  insert_number(&root, 20);
  insert_number(&root, 10);
  insert_number(&root, 12);
  insert_number(&root, 30);

  print_tree(root);

  printf("%d (%d)", 16, find_number(root, 16));
  printf("%d (%d)", 2, find_number(root, 2));
  printf("%d (%d)", 14, find_number(root, 14));

  return 0;
}
