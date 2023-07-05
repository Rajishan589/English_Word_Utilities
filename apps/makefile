CC=gcc
CFLAGS=-Wall -I./../trie -I./../util
LIBRARIES=-L./../util -lwordutils -L./../trie -ltrie


maxchain: maxchain.c
	$(CC) $(CFLAGS) maxchain.c $(LIBRARIES) -o maxchain 
	LD_LIBRARY_PATH=./../util:./../trie ./maxchain
	rm -f maxchain
subwords: subwords.c 
	$(CC) $(CFLAGS) subwords.c $(LIBRARIES) -o subwords
	LD_LIBRARY_PATH=./../util:./../trie ./subwords
	rm -f subwords

clean : 
	-rm -f maxchain subwords