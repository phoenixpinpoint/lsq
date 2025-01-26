test:
	gcc -Wall -Werror tests/test.c -o tests/test; tests/test

list:
	gcc -Wall -Werror -DSTANDALONE tests/lists.c -o tests/lists; tests/lists;

queue:
	gcc -Wall -Werror -DSTANDALONE tests/queues.c -o tests/queues; tests/queues;

stack:
	gcc -Wall -Werror -DSTANDALONE tests/stacks.c -o tests/stacks; tests/stacks;

clean: 
	rm -rf ./tests/test
	rm -rf ./tests/lists
	rm -rf ./tests/queues
	rm -rf ./tests/stacks
