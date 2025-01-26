#include <stdio.h>

#include "../lsq.h"

#ifdef STANDALONE
#include "../lsq.c"
#endif

int main() {
  printf("Queue Tetsts\n");
  lsq_t queue = {.current = 0, .head = 0, .last = 0, .length = 0};

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int z = 0;

  lsq_node_t one = {.value = &a, .next = 0, .prev = 0};
  lsq_node_t two = {.value = &b, .next = 0, .prev = 0};
  lsq_node_t three = {.value = &c, .next = 0, .prev = 0};
  lsq_node_t four = {.value = &d, .next = 0, .prev = 0};
  lsq_node_t zero = {.value = &z, .next = 0, .prev = 0};

  lsq_push(&queue, &one);   // 1
  lsq_push(&queue, &two);   // 2,1
  lsq_push(&queue, &three); // 3,2,1
  lsq_push(&queue, &four);  // 4,3,2,1
  lsq_push(&queue, &zero);  // 0,4,3,2,1
  lsq_node_t *zPtr = lsq_pop(&queue);

  printf("Popped %d\n", *(int *)zPtr->value);

  for (int i = 0; i < queue.length; i++) {
    printf("%d", *(int *)lsq_get_n(&queue, i)->value);
    if (i != queue.length - 1) {
      printf(",");
    }
  }
  printf("\n");

  return 0;
}
