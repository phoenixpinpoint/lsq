#include <stdio.h>

#include "../lsq.h"

#ifdef STANDALONE
#include "../lsq.c"
#endif

void run_queue_tests() {
  printf("Queue Tests\n");

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

  lsq_enque(&queue, &one);   // 1
  lsq_enque(&queue, &two);   // 1,2
  lsq_enque(&queue, &three); // 1,2,3
  lsq_enque(&queue, &four);  // 1,2,3,4
  lsq_enque(&queue, &zero);  // 1,2,3,4,0

  lsq_node_t *aPtr = lsq_deque(&queue);

  printf("Deque: %d\n", *(int *)aPtr->value);

  for (int i = 0; i < queue.length; i++) {
    printf("%d", *(int *)lsq_get_n(&queue, i)->value);
    if (i != queue.length - 1) {
      printf(",");
    }
  }
  printf("\n");

  return;
}

#ifdef STANDALONE
int main() { run_queue_tests(); }
#endif
