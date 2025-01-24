#ifndef LSQ_H
#define LSQ_H

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

// LSQ Iterator
void lsq_reset(lsq_t *list);

bool lsq_next(lsq_t *list);

bool lsq_prev(lsq_t *list);

// LSQ Stack Fuctions
void lsq_push(lsq_t *list, lsq_node_t *node);

lsq_node_t *lsq_pop(lsq_t *list);

lsq_node_t *lsq_stack_get_n(lsq_t *list, int n);

lsq_node_t *lsq_stack_peak(lsq_t *list);

// LSQ Queue Functions
void lsq_enque(lsq_t *list, lsq_node_t *node);

lsq_node_t *lsq_deque(lsq_t *list);

lsq_node_t *lsq_queue_get_n(lsq_t *list, int n);

lsq_node_t *lsq_queue_peak(lsq_t *list);

#endif
