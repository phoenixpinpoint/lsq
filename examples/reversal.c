#include "../lsq.c"
#include <stdio.h>

int main() {
  /*
   * This example takes a simple string and reverses it without making a copy of
   * the string. That being said this isn't very efficient due to additional
   * memory needed for the lsq_node_t's, and the same O(n) time complexity to
   * load the message into list.
   *
   * A better solution to that would be just to print it backwards with a for
   * loop.
   */
  char message[] = "Hello, this is a string that has been reversed\0";

  lsq_t *message_list = lsq_init();

  for (int i = 0; i < strlen(message); i++) {
    lsq_node_t *c = lsq_node_init();
    c->value = &message[i];
    lsq_push(message_list, c);
  }

  lsq_reset(message_list);
  lsq_node_t *item = message_list->current;
  while (item) {
    printf("%c", *(char *)item->value);
    if (lsq_next(message_list)) {
      item = message_list->current;
    } else {
      item = 0;
    }
  }
  printf("\n");

  return 0;
}
