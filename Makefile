test: 
	gcc -Wall -Werror tests/test.c -o tests/test; tests/test

clean: 
	rm -rf ./tests/test
