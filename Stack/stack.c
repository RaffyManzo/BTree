#include "stack.h"
#include <stdlib.h>

struct stack {
  List list;
};

Stack newStack() {
  Stack newStack = malloc(sizeof(struct stack));
  newStack->list = newList();
  return newStack;
}

int isEmptyStack(Stack s) { return isEmpty(s->list); }

void push(Stack s, Item e) { return addHead(s->list, e); }

Item pop(Stack s) { return removeHead(s->list); }

Item top(Stack s) { return getHead(s->list); }

void printStack(Stack s) { printList(s->list); }
