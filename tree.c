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

int main() {
  treenode *n1 = create_node(10);
  treenode *n2 = create_node(11);
  treenode *n3 = create_node(12);
  treenode *n4 = create_node(13);
  treenode *n5 = create_node(14);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;

  print_tree(n1);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);

  return 0;
}
