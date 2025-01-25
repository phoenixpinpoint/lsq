#include "lsq.h"

// Remove after ts

lsq_t *lsq_init() {
  lsq_t *instance = malloc(sizeof(lsq_t));
  instance->head = 0;
  instance->current = 0;
  instance->last = 0;
  instance->length = 0;
  return instance;
}

lsq_node_t *lsq_node_init() {
  lsq_node_t *instance = malloc(sizeof(lsq_node_t));
  instance->next = 0;
  instance->prev = 0;
  instance->value = 0;
  return instance;
}

void lsq_append(lsq_t *list, lsq_node_t *node) {
  if (list->length == 0) {
    list->head = node;
    list->last = node;
    list->length = list->length + 1;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
    list->length = list->length + 1;
  }
}

void lsq_prepend(lsq_t *list, lsq_node_t *node) {
  if (list->length == 0) {
    lsq_append(list, node);
  } else {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->length = list->length + 1;
  }
}

lsq_node_t *lsq_remove_n(lsq_t *list, int n) {
  if (n == 0) { // First
    return lsq_pop(list);
  } else if (n == list->length - 1) { // Last
    lsq_node_t *temp = list->last;
    list->last = list->last->prev;
    list->last->next = 0;
    list->length = list->length - 1;
    return temp;
  } else { // nth
    lsq_node_t *temp = lsq_get_n(list, n);
    lsq_node_t *left = temp->prev;
    lsq_node_t *right = temp->next;

    left->next = right;
    right->prev = left;

    list->length = list->length - 1;

    return temp;
  }
}

void lsq_add_n(lsq_t *list, lsq_node_t *node, int n) {
  if (n == 0) { // First
    return lsq_push(list, node);
  } else if (n == list->length - 1) { // Last
    return lsq_append(list, node);
  } else { // Nth
    lsq_node_t *temp = lsq_get_n(list, n);
    lsq_node_t *left = temp->prev;
    lsq_node_t *right = temp->next;

    left->next = node;
    node->prev = left;

    right->prev = node;
    node->next = right;

    list->length = list->length + 1;

    return;
  }
}

void lsq_reset(lsq_t *list) { list->current = list->head; }

bool lsq_next(lsq_t *list) {
  if (list->current->next != 0) {
    list->current = list->current->next;
    return true;
  } else {
    return false;
  }
}

bool lsq_prev(lsq_t *list) {
  if (list->current->prev != 0) {
    list->current = list->current->prev;
    return true;
  } else {
    return false;
  }
}

void lsq_push(lsq_t *list, lsq_node_t *node) { return lsq_prepend(list, node); }

void lsq_enque(lsq_t *list, lsq_node_t *node) { lsq_append(list, node); }

lsq_node_t *lsq_deque(lsq_t *list) { return lsq_pop(list); }

lsq_node_t *lsq_pop(lsq_t *list) {
  lsq_node_t *temp = 0;
  if (list->length > 0) {
    if (list->length == 1) {
      temp = list->head;
      list->head = 0;
      list->last = 0;
      list->length = list->length - 1;
    } else {
      temp = list->head;
      list->head = temp->next;
      list->head->prev = 0;
      list->length = list->length - 1;
    }
  }
  return temp;
}

lsq_node_t *lsq_get_n(lsq_t *list, int n) {
  if (n < 0 || n > list->length - 1) {
    return (lsq_node_t *)0;
  } else {
    if (n == 0) {
      return list->head;
    }
    lsq_reset(list);
    for (int i = 0; i < n; i++) {
      lsq_next(list);
    }
    return list->current;
  }
}

lsq_node_t *lsq_stack_peak(lsq_t *list) { return list->head; }

lsq_node_t *lsq_queue_peak(lsq_t *list) { return list->last; }
