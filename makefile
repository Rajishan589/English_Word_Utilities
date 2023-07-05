libraries:
	cd trie && make
	cd trie && sudo make install
	cd util && make
	cd util && sudo make install

clean:
	cd trie && sudo make clean
	cd util && sudo make clean
	cd apps && sudo make clean

maxchain:
	export LD_LIBRARY_PATH=/usr/local/lib; cd apps; make maxchain;

subwords: 
	export LD_LIBRARY_PATH=/usr/local/lib; cd apps; make subwords;