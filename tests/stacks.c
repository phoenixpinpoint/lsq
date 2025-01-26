#include <stdio.h>

#include "../lsq.h"

#ifdef STANDALONE
#include "../lsq.c"
#endif

void run_stack_tests() {
  printf("Stack Tetsts\n");
  lsq_t stack = {.current = 0, .head = 0, .last = 0, .length = 0};

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

  lsq_push(&stack, &one);   // 1
  lsq_push(&stack, &two);   // 2,1
  lsq_push(&stack, &three); // 3,2,1
  lsq_push(&stack, &four);  // 4,3,2,1
  lsq_push(&stack, &zero);  // 0,4,3,2,1
  lsq_node_t *zPtr = lsq_pop(&stack);

  printf("Popped %d\n", *(int *)zPtr->value);

  for (int i = 0; i < stack.length; i++) {
    printf("%d", *(int *)lsq_get_n(&stack, i)->value);
    if (i != stack.length - 1) {
      printf(",");
    }
  }
  printf("\n");

  return;
}

#ifdef STANDALONE
int main() {
  run_stack_tests();
  return 0;
}
#endif
