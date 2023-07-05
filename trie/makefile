
CC = gcc
CFLAGS = -Wall -fPIC -I.

library : trie.o
	gcc -shared -o libtrie.so trie.o 

trie.o : trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

install : library
	sudo cp libtrie.so  /usr/local/lib
	sudo cp trie.h /usr/local/include

clean :
	rm  -f /usr/local/include/trie.h
	rm  -f /usr/local/lib/libtrie.so
	-rm -f trie.o
	-rm -f libtrie.so