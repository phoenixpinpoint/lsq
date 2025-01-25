#include <stdio.h>

#include "../lsq.h"

#ifdef STANDALONE
#include "../lsq.c"
#endif

int main() {
  printf("Standard List Tests\n");

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int z = 0;

  lsq_t list = {.head = 0, .last = 0, .length = 0, .current = 0};
  lsq_node_t one = {.value = &a, .next = 0, .prev = 0};
  lsq_node_t two = {.value = &b, .next = 0, .prev = 0};
  lsq_node_t three = {.value = &c, .next = 0, .prev = 0};
  lsq_node_t four = {.value = &d, .next = 0, .prev = 0};
  lsq_node_t zero = {.value = &z, .next = 0, .prev = 0};

  lsq_append(&list, &one);    // 1
  lsq_append(&list, &two);    // 1,2
  lsq_append(&list, &three);  // 1,2,3
  lsq_prepend(&list, &zero);  // 0,1,2,3
  lsq_remove_n(&list, 1);     // 0,2,3
  lsq_add_n(&list, &four, 2); // 0,2,4,3

  for (int i = 0; i < list.length; i++) {
    printf("%d", *(int *)lsq_get_n(&list, i)->value);
    if (i != list.length - 1) {
      printf(",");
    }
  }
  printf("\n");

  return 0;
}
