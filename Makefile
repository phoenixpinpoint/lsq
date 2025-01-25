test:
	gcc -Wall -Werror tests/test.c -o tests/test; tests/test

list:
	gcc -Wall -Werror -DSTANDALONE tests/lists.c -o tests/lists; tests/lists;

clean: 
	rm -rf ./tests/test
	rm -rf ./tests/lists
