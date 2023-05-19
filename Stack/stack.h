#include "../item.h"
#include "list.h"

typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack);
Item top(Stack);
void push(Stack, Item);
Item pop(Stack);
void printStack(Stack);