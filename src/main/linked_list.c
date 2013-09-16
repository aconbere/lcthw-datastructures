#include "linked_list.h"

List *List_create() {
  return calloc(1, sizeof(List));
}

void List_destroy(List *list) {
  LIST_FOREACH(list, first, next, cur) {
    if (cur->prev) {
      free(cur->prev);
    }
  }
  free(list->last);
  free(list);
}

void List_clear_destroy(List *list) {
  List_clear(list);
  List_destroy(list);
}

void List_clear(List *list) {
  LIST_FOREACH(list, first, next, cur) {
    if (cur->value) {
      free(cur->value);
    }
  }
}

void List_push(List *list, void *value) {
  ListNode * new_node = calloc(1, sizeof(ListNode));
  check_mem(new_node);
  new_node->value = value;

  if (list->last == NULL) {
    list->first = new_node;
    list->last = new_node;
  } else {
    list->last->next = new_node;
    new_node->prev = list->last;
    list->last = new_node;
  }

  list->count++;
error:
  return;
}

void List_unshift(List *list, void *value) {
  ListNode * new_node = calloc(1, sizeof(ListNode));
  check_mem(new_node);
  new_node->value = value;

  if (list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
  } else {
    list->first->next = new_node;
    new_node->prev = list->last;
    list->last = new_node;
  }

  list->count++;
error:
  return;
}

void *List_shift(List *list) {
  ListNode *node = list->first;
  return node == NULL ? NULL : List_remove(list, list->first);
}

void *List_remove(List *list, ListNode *node) {
  void *result = NULL;

  check(list->first && list->last, "List is empty.");
  check(node, "node can't be NULL");

  if (list->first == node && list->last == node) {
    // we are the only node
    list->first = NULL;
    list->last = NULL;
  } else if (list->first == node) {
    list->first = node->next;
    list->first->prev = NULL;
  } else if (list->last == node) {
    list->last = node->prev;
    list->last->next = NULL;
  } else {
    // simply excise the current node;
    ListNode *next = node->next;
    ListNode *prev = node->prev;

    prev->next = next;
    next->prev = prev;
  }

  list->count--;
  result = node->value;
  free(node);

error:
  return result;
}

void *List_pop(List *list) {
  ListNode *node = list->last;
  return node == NULL ? NULL : List_remove(list, list->last);
}
