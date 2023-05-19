#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Item value;
  struct node *left;
  struct node *right;
};

BTree newTree() { return NULL; }

int isEmptyTree(BTree btree) {
  if (btree == NULL)
    return 1;
  return 0;
}

BTree buildTree(BTree left, BTree right, Item root) {
  BTree btree = malloc(sizeof(struct node));
  btree->value = root;
  btree->left = left;
  btree->right = right;
  return btree;
}

Item getBTreeRoot(BTree btree) {
  if (isEmptyTree(btree))
    return NULL;
  return (btree->value);
}

BTree getLeft(BTree btree) {
  if (isEmptyTree(btree))
    return NULL;
  return (btree->left);
}
BTree getRight(BTree btree) {
  if (isEmptyTree(btree))
    return NULL;
  return (btree->right);
}

void preOrder(BTree btree) {
  if (!isEmptyTree(btree)) {
    outputItem(btree->value);
    preOrder(btree->left);
    preOrder(btree->right);
  }
}

void iPreOrder(BTree btree) {
  BTree current;
  Stack s = newStack();

  push(s, btree);

  while (!isEmptyStack(s)) {
    // Pop node from stack
    current = pop(s);

    outputItem(current->value);

    if (current->right)
      push(s, current->right);
    if (current->left)
      push(s, current->left);
  }
}

void postOrder(BTree btree) {
  if (!isEmptyTree(btree)) {
    postOrder(btree->left);
    postOrder(btree->right);
    outputItem(btree->value);
  }
}

void iPostOrder(BTree btree) {
  BTree current = btree;
  BTree lastVisited = NULL;
  Stack s = newStack();

  while (!isEmptyStack(s) || !isEmptyTree(current)) {
    if (!isEmptyTree(current)) {
      push(s, current);
      current = current->left;
    } else {
      BTree lastVisitedRoot = top(s);

      if (isEmptyTree(lastVisitedRoot->right) && current == lastVisitedRoot) {
        lastVisited = pop(s);
        outputItem(lastVisited->value);
      } else
        current = lastVisitedRoot->right;
    }
  }
}

void inOrder(BTree btree) {
  if (!isEmptyTree(btree)) {
    inOrder(btree->left);
    outputItem(btree->value);
    inOrder(btree->right);
  }
}

void iInOrder(BTree btree) {
  BTree current = btree;
  BTree lastVisited = NULL;
  Stack s = newStack();

  while (!isEmptyStack(s) || !isEmptyTree(current)) {
    if (!isEmptyTree(current)) {
      push(s, current);
      current = current->left;
    } else {
      lastVisited = pop(s);
      if (!isEmptyTree(lastVisited->right))
        current = lastVisited->right;
      outputItem(lastVisited->value);
    }
  }
}

int getBTreeHeight(BTree btree, int i) {
  if (!isEmptyTree(btree)) {
    i++;
    int leftH = getBTreeHeight(btree->left, i);
    int rightH = getBTreeHeight(btree->right, i);
    switch (leftH >= rightH) {
    case 1:
      return leftH;
    case 0:
      return rightH;
    }
  } else
    return i;
}

int getBTreeNodes(BTree btree) {
  if (!isEmptyTree(btree)) {
    return 1 + getBTreeNodes(btree->left) + getBTreeNodes(btree->right);
  } else
    return 0;
}

void levelsOrder(BTree btree) {
  if (!isEmptyTree(btree)) {
    BTree *queue = malloc(getBTreeNodes(btree) * sizeof(BTree));
    BTree current;

    queue[0] = btree;

    for (int currentRoot = 0, rearTree = 1; currentRoot < rearTree;) {
      current = queue[currentRoot++];
      if (!current)
        fprintf(stderr, "Assegnazione da queue non riuscita");
      outputItem(current->value);

      if (getLeft(current))
        queue[rearTree++] = getLeft(current);

      if (getRight(current))
        queue[rearTree++] = getRight(current);
    }
  }
}

Item search(BTree btree, Item k) {
  if (!isEmptyTree(btree)) {
    if (cmpItem(btree->value, k) == 0)
      return btree->value;
    Item tmp = search(btree->right, k);
    if (!tmp)
      return search(btree->left, k);
    else
      return tmp;
  } else
    return NULL;
}

Item max(BTree btree) {
  if (!isEmptyTree(btree)) {
    Item left = max(btree->left);
    Item right = max(btree->right);

    if (cmpItem(left, btree->value) > 0 && cmpItem(left, right) > 0)
      return left;
    else if (cmpItem(right, btree->value) > 0 && cmpItem(right, left) > 0)
      return right;
    else
      return btree->value;
  } else
    return NULL;
}

int isEquals(BTree btree1, BTree btree2) {
  if (isEmptyTree(btree1) && isEmptyTree(btree2))
    return 1;
  else if (isEmptyTree(btree1) || isEmptyTree(btree2))
    return 0;

  if (isEquals(btree1->left, btree2->left) &&
      isEquals(btree1->right, btree2->right) &&
      cmpItem(btree1->value, btree2->value) == 0) {
    return 1;
  }
  return 0;
}