#include "list.h"
#include <stdlib.h>

struct list {
  int size;
  struct node *head;
};

struct node {
  Item value;
  struct node *next;
};

List newList() {
  List list = malloc(sizeof(struct list));
  list->size = 0;
  list->head = NULL;
  return list;
}

int isEmpty(List list) {
  if (list->size == 0)
    return 1;

  return 0;
}

void addHead(List list, Item el) {

  struct node *newHead = malloc(sizeof(struct node));

  newHead->value = el;
  newHead->next = list->head;

  list->head = newHead;

  (list->size)++;
}

Item removeHead(List list) {

  if (isEmpty(list))
    return NULL;

  struct node *temp = list->head;
  list->head = temp->next;

  Item el = temp->value;
  free(temp);

  (list->size)--;

  return el;
}

Item getHead(List list) {

  if (isEmpty(list))
    return NULL;

  return list->head->value;
}

int sizeList(List list) { return list->size; }

void printList(List list) {

  struct node *p;
  for (p = list->head; p != NULL; p = p->next) {
    outputItem(p->value);
  }
}

Item searchListItem(List l, Item q, int *pos) {
  struct node *p;
  *pos = 0;
  for (p = l->head; p != NULL; p = p->next, (*pos)++) {
    if (cmpItem(q, p->value) == 0) {
      return p->value;
    }
  }
  *pos = -1;
  return NULL;
}

Item removeListItem(List l, Item q) {
  struct node *prev, *p;
  Item val;
  if (isEmpty(l))
    return NULL;
  for (p = l->head; p != NULL; prev = p, p = p->next) {
    if (cmpItem(q, p->value) == 0) {
      if (p == l->head)
        return removeHead(l);
      else // si può anche evitare
      {
        prev->next = p->next;
        val = p->value; // assegno il valore precedente dell'item
        (l->size)--;    // decremento taglia lista
        free(p);        // libero memoria p
        return val;     // ritorno l'item
      }
    }
  }
  return NULL; // caso in cui non è stato trovato
}

Item removeListPos(List l, int pos) {
  struct node *prev, *p;
  Item val;
  int i;
  if (isEmpty(l) || pos < 0 || pos >= l->size) // controllo precondizione
    return NULL;
  for (i = 0, p = l->head; p != NULL; prev = p, p = p->next, i++) {
    if (i == pos) {
      if (p == l->head)
        return removeHead(l);
      else // si può anche evitare
      {
        prev->next = p->next;
        val = p->value; // assegno il valore precedente dell'item
        (l->size)--;    // decremento taglia lista
        free(p);        // libero memoria p
        return val;     // ritorno l'item
      }
    }
  }
  return NULL;
}

int addListPos(List list, Item el, int pos) {
  struct node *p, *newNode;
  int i;

  if (pos < 0 || pos > list->size) {
    return 0;
  }
  if (pos == 0) {
    addHead(list, el);
    return 1;
  }
  for (i = 0, p = list->head; i < pos - 1; p = p->next, i++)
    ;

  newNode = malloc(sizeof(struct node));
  newNode->next = p->next;
  newNode->value = el;
  p->next = newNode;

  (list->size)++;
  return 1;
}

int addListTail(List list, Item el) {
  return (addListPos(list, el, list->size));
}

void reverseList(List list) {
  struct node *prev = NULL, *p, *temp;

  for (p = list->head; p != NULL; prev = p, p = temp) {
    temp = p->next;
    p->next = prev;
  }
  list->head = prev;
}

List cloneList(List list) {
  List l2 = newList();
  struct node *p;

  for (p = list->head; p != NULL; p = p->next) {
    addListTail(l2, p->value);
  }
  return l2;
}
