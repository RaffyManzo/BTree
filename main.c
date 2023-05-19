#include "btree.h"
#include "item.h"
#include <stdio.h>

int main() {
  BTree h, a, c, d, l, p, s, o, q;
  q = buildTree(NULL, NULL, "q");
  o = buildTree(NULL, NULL, "o");
  s = buildTree(NULL, NULL, "s");
  d = buildTree(NULL, NULL, "d");
  p = buildTree(NULL, NULL, "p");
  l = buildTree(o, q, "l");
  a = buildTree(d, l, "a");
  c = buildTree(p, s, "c");
  h = buildTree(a, c, "h");

  postOrder(h);
  printf("\n\n");
  // iPostOrder(h);
  printf("Searching l: \t");
  outputItem(search(h, "l"));
  printf("\n\nMax: \t");
  outputItem(max(h));

  printf("\n\nAre equals?: \t %d", isEquals(h, c));

  return 0;
}