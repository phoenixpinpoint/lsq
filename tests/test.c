#include <stdio.h>

#include "../lsq.c"
#include "../lsq.h"

int main() {
  printf("LINKED LIST TESTS:\n");

  lsq_t stackTest = {.head = 0, .length = 0, .current = 0, .last = 0};

  int a = 1;
  int b = 2;
  int c = 3;

  lsq_node_t nodeOne = {.value = &a, .next = 0, .prev = 0};
  lsq_node_t nodeTwo = {.value = &b, .next = 0, .prev = 0};
  lsq_node_t nodeThree = {.value = &c, .next = 0, .prev = 0};

  printf("Starting Nodes: \n%d\n", *(int *)nodeOne.value);
  printf("%d\n", *(int *)nodeTwo.value);
  printf("%d\n", *(int *)nodeThree.value);

  printf("Stack Tests State Checks:\n");
  printf("Initial Size %ld\n", stackTest.length);

  lsq_push(&stackTest, &nodeOne);
  lsq_push(&stackTest, &nodeTwo);
  lsq_push(&stackTest, &nodeThree);

  lsq_reset(&stackTest);
  printf("%p->%d\n", stackTest.current, *(int *)stackTest.current->value);
  while (lsq_next(&stackTest)) {
    printf("%p->%d\n", stackTest.current, *(int *)stackTest.current->value);
  }

  for (int i = 0; i < stackTest.length; i++) {
    printf("%d\n", *(int *)lsq_stack_get_n(&stackTest, i)->value);
  }

  lsq_node_t *item = lsq_pop(&stackTest);
  while (item != 0) {
    printf("%d\n", *(int *)(item->value));
    item = lsq_pop(&stackTest);
  }

  lsq_push(&stackTest, &nodeOne);

  printf("%d\n", *(int *)lsq_pop(&stackTest)->value);

  // Queue Tests
  lsq_reset(&stackTest);

  printf("=====\n");

  lsq_enque(&stackTest, &nodeOne);
  lsq_enque(&stackTest, &nodeTwo);
  lsq_enque(&stackTest, &nodeThree);

  for (int i = 0; i < stackTest.length; i++) {
    printf("%d\n", *(int *)lsq_queue_get_n(&stackTest, i)->value);
  }

  item = 0;
  item = lsq_deque(&stackTest);
  while (item != 0) {
    printf("%d\n", *(int *)(item->value));
    item = lsq_deque(&stackTest);
  }
  return 0;
}
