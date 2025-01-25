#ifndef LSQ_H
#define LSQ_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *value;
  void *prev;
  void *next;
} lsq_node_t;

typedef struct {
  lsq_node_t *head;
  lsq_node_t *last;
  size_t length;
  lsq_node_t *current;
} lsq_t;

lsq_t *lsq_init();

lsq_node_t *lsq_node_init();

// LSQ Iterator
void lsq_reset(lsq_t *list);

bool lsq_next(lsq_t *list);

bool lsq_prev(lsq_t *list);

// LSQ Linked List Functions
void lsq_append(lsq_t *list, lsq_node_t *node);

void lsq_prepend(lsq_t *list, lsq_node_t *node);

lsq_node_t *lsq_get_n(lsq_t *list, int n);

lsq_node_t *lsq_remove_n(lsq_t *list, int n);

void lsq_add_n(lsq_t *list, lsq_node_t *node, int n);

// LSQ Stack Fuctions
void lsq_push(lsq_t *list, lsq_node_t *node);

lsq_node_t *lsq_pop(lsq_t *list);

lsq_node_t *lsq_stack_peak(lsq_t *list);

// LSQ Queue Functions
void lsq_enque(lsq_t *list, lsq_node_t *node);

lsq_node_t *lsq_deque(lsq_t *list);

lsq_node_t *lsq_queue_peak(lsq_t *list);

#endif
