
#include <dictload.h>

#define str_size 100

struct arrofstr{
    char permu_str[str_size];

};

void findPermutations(dict * T,char str[], int index, int n,struct arrofstr * node);
void frontstring(char str[],char c);
void frontremovestring(char str[]);
void lastremovestring(char str[]);
char * addbefore(dict * T,char str[]);
char * addafter(dict * T,char str[]);
struct arrofstr * anagrams(dict * T, char S[]);
bool shouldSwap(char str[], int start, int curr);
void findPermutations(dict * T,char str[], int index, int n,struct arrofstr * node);