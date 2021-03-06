#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BTree *btree_create(char data, int freq, struct BTree *left,
                           struct BTree *right) {
  struct BTree *root = malloc(sizeof(struct BTree));
  root->data = data;
  root->freq = freq;
  root->code[0] = '\0';
  root->left = left;
  root->right = right;

  return root;
}

void btree_destroy(struct BTree *root) {
  if (root == NULL) {
    return;
  }

  btree_destroy(root->left);
  btree_destroy(root->right);
  free(root);
}

int btree_depth(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  int ld = btree_depth(root->left);
  int rd = btree_depth(root->right);

  return 1 + (ld > rd ? ld : rd);
}

int btree_leaves(struct BTree *root) {
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    return 1;
  }

  return btree_leaves(root->left) + btree_leaves(root->right);
}

// 判断两棵树是否相同, 相同返回1， 不同返回0
bool btree_is_same(struct BTree *a, struct BTree *b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  return a->data == b->data && btree_is_same(a->left, b->left) &&
         btree_is_same(a->right, b->right);
}

// 判断两棵树是否同构，即能够通过若干次左右子树的交换由a变为b，同构返回1，不同构返回2
bool btree_is_isomorphic(struct BTree *a, struct BTree *b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  return a->data == b->data && ((btree_is_isomorphic(a->left, b->left) &&
                                 btree_is_isomorphic(a->right, b->right)) ||
                                (btree_is_isomorphic(a->left, b->right) &&
                                 btree_is_isomorphic(a->right, b->left)));
}
