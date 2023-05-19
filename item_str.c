#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

Item inputItem() {
  char *p = malloc(MAX * sizeof(char));
  scanf("%s", p);

  return p;
}

void outputItem(Item a) {
  char *p = a;
  printf("%s ", p);
}
int cmpItem(Item a, Item b) {
  if (!a)
    return -1;
  else if (!b)
    return 1;
  char *p1 = a;
  char *p2 = b;

  return strcmp(p1, p2);
}