#include<stdbool.h>

struct trie {
    char char_label;
    bool eow;
    struct trie * first_child;
    struct trie * next_sibling;
};

typedef struct trie trienode;

struct trie * trieinit();

struct trie * triechar(char a);

struct trie * insert(struct trie* curr,const char a);
void trieinsert(struct trie * T,const char * S);

void addstring(char c[],char a);

int triesearch(struct trie * T,const  char * S);

void sibling(struct trie * T, char str[]);

void help_listall(struct trie * T,char str[]);

void listall(struct trie * T);