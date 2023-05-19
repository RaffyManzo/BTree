#include "Stack/stack.h"
#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);

// Pre order algorithm for Btree visit
void preOrder(BTree);
void iPreOrder(BTree);
// Post order algorithm for Btree visit
void postOrder(BTree);
void iPostOrder(BTree);

// In order algorithm for Btree visit
void inOrder(BTree);
void iInOrder(BTree btree);

// Determine the height
int getBTreeHeight(BTree, int);
// Determine number of nodes in a binary tree
int getBTreeNodes(BTree);
// Visit by levels of a binary tree
void levelsOrder(BTree);
// Create the three visits of the binary tree in an iterative manner, using a
// stack
Item max(BTree);
Item search(BTree, Item);
int isEquals(BTree, BTree);