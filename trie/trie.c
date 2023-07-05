#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <trie.h>


// Initialize a new trie node
struct trie * trieinit(){
    struct trie * tempVar=(struct trie *)malloc(sizeof(struct trie));
    tempVar->char_label='-'; // set the character label to a default value
    tempVar->eow=false; // set the end-of-word flag to false
    tempVar->first_child=NULL; // initialize the first child pointer to NULL
    tempVar->next_sibling=NULL; // initialize the next sibling pointer to NULL
    return tempVar; // return the newly created node
}

// Create a new trie node with the given character label
struct trie * triechar(char a){
    struct trie * tempVar=(struct trie *)malloc(sizeof(struct trie));
    tempVar->char_label=a; // set the character label to the given value
    tempVar->eow=false; // set the end-of-word flag to false
    tempVar->first_child=NULL; // initialize the first child pointer to NULL
    tempVar->next_sibling=NULL; // initialize the next sibling pointer to NULL
    return tempVar; // return the newly created node
}

struct trie * insert(struct trie* currentTrie, char a){
    struct trie * temp;
    if(currentTrie->first_child==NULL){
        currentTrie->first_child=triechar(a);
        return currentTrie->first_child;

    }
    currentTrie=currentTrie->first_child;
    
    struct trie * prev=currentTrie;
    if(currentTrie->char_label==a){
        return currentTrie;
    }
    else{
        for(;currentTrie!=NULL;){
            if(currentTrie->char_label==a){
                return currentTrie;
            }
            prev=currentTrie;
            currentTrie=currentTrie->next_sibling;
        }
    }
    if(currentTrie==NULL){
        return prev->next_sibling=triechar(a);
    }
    return temp=currentTrie;
}

void trieinsert(struct trie * T,const char * S){
    if(T==NULL){
        T=trieinit();
    }

    int length=strlen(S);
    int level=0;
        struct trie * currentTrie =T;
    for(level=0;level<length;level++){

        currentTrie=insert(currentTrie,S[level]);
    }
    currentTrie->eow=true;
}

void addstring(char *c,char a){
    int length=strlen(c);
    c[length]=a;
    c[length+1]='\0';
}

int triesearch(struct trie * T,const char * S){
    T=T->first_child;
    if(T==NULL) return 0;
    struct trie * t=T;
    for(int i=0;i<strlen(S);i++){
        while(t!=NULL){
            if(t->char_label==S[i]){
                if(i==(strlen(S)-1)&&(t->first_child==NULL||t->eow==true)){
                    return 1;
                }
                t=t->first_child;
                break;
            }
            else{
                t=t->next_sibling;
            }
        }

        if(t==NULL){
            return 0;
        }

    }
    return 0;

}


void listprint(trienode *T, char *pre, int size)
{
    if (T == NULL)
        return;
    while (T != NULL)
    {
        pre[size] = T->char_label;
        if (T->eow == true)
        {
            pre[size + 1] = '\0';
            printf("%s\n", pre);
        }

        if (T != NULL)
        {
            listprint(T->first_child, pre, size + 1);
        }
        T = T->next_sibling;
    }
}

void listall(struct trie *T)
{
    char *pre = (char *)malloc(100 * sizeof(char));
    listprint(T->first_child ,pre, 0);

    free(pre);
}

