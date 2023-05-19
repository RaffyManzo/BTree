#include "item.h"
#include <stdio.h>
#include <stdlib.h>

Item inputItem() {
  int *p = malloc(sizeof(int));
  scanf("%d", p);

  return p;
}

void outputItem(Item a) {
  int *p = a;
  printf("%d ", *p);
}

int cmpItem(Item a, Item b) {
  if (!a)
    return 1;
  else if (!b)
    return -1;
  int *p1 = a;
  int *p2 = b;

  return (*p1 - *p2);
}
