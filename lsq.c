#include <stdbool.h>
#include <stdint.h>

#include "lsq.h"

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

void lsq_push(lsq_t *list, lsq_node_t *node) {
  if (list->length == 0) {
    list->head = node;
    list->current = node;
    list->last = node;
    list->length = list->length + 1;
  } else {
    // Set the current heads previous node to the new node
    list->head->prev = node;
    // Set the new nodes next value to the current head
    node->next = list->head;
    // Set the lists head to the new node
    list->head = node;
    // Increment the node coutner
    list->length = list->length + 1;
  }
  return;
}

void lsq_enque(lsq_t *list, lsq_node_t *node) { lsq_push(list, node); }

lsq_node_t *lsq_deque(lsq_t *list) {
  lsq_node_t *temp = 0;
  if (list->length > 0) {
    if (list->length == 1) {
      temp = list->head;
      list->head = 0;
      list->last = 0;
      list->length = list->length - 1;
    } else {
      temp = list->last;
      list->last = temp->prev;
      list->last->next = 0;
      list->length = list->length - 1;
    }
  }
  return temp;
}

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

lsq_node_t *lsq_stack_get_n(lsq_t *list, int n) {
  // printf("Getting Value %d\n", n);
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

lsq_node_t *lsq_queue_get_n(lsq_t *list, int n) {
  if (n < 0 || n > list->length - 1) {
    return (lsq_node_t *)0;
  } else {
    list->current = list->last;
    for (int i = n; i >= 0; i--) {
      if (n == 0) {
        return list->current;
      }
      lsq_prev(list);
    }
    return list->current;
  }
}

lsq_node_t *lsq_stack_peak(lsq_t *list) { return list->head; }

lsq_node_t *lsq_queue_peak(lsq_t *list) { return list->last; }
