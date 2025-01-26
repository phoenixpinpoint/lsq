#include <stdio.h>

#include "../lsq.c"
#include "../lsq.h"

#include "./lists.c"
#include "./queues.c"
#include "./stacks.c"

int main() {
  printf("LSQ TESTS:\n");
  run_list_tests();
  run_queue_tests();
  run_stack_tests();
  return 0;
}
