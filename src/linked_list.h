#ifndef LinkedList
#define LinkedList

#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_create();
void List_destroy();
void List_clear();
void List_clear_destroy();

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first == NULL ? NULL : (A)->first->value)
#define List_last(A) ((A)->last == NULL ? NULL : (A)->last->value)

void List_push(List *list, void *value);
void *List_pop();

void List_unshift();
void *List_shift();

void *List_remove();

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                 ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)
#endif
