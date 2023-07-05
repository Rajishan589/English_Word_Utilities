
CFLAGS = -Wall -fPIC -I.

library : dictload.o dictutils.o
	gcc -shared -o libwordutils.so dictload.o dictutils.o -ltrie

dictload.o : dictload.c dictload.h dicttype.h /usr/local/include/trie.h
	gcc $(CFLAGS) -c dictload.c

dictutils.o : dictutils.c dictutils.h /usr/local/include/trie.h
	gcc $(CFLAGS) -c dictutils.c 

install : library
	sudo cp wordutils.h dicttype.h dictutils.h dictload.h /usr/local/include
	sudo cp libwordutils.so /usr/local/lib

clean :
	rm  -f /usr/local/include/wordutils.h
	rm  -f /usr/local/include/dicttype.h
	rm  -f /usr/local/include/dictutils.h
	rm  -f /usr/local/include/dictload.h

	rm  -f /usr/local/lib/libwordutils.so
	-rm -f dictload.o dictutils.o
	-rm -f libwordutils.so
	