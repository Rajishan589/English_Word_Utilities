#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define befaf_size 100 // Define constant for size of strings used
#include <dictutils.h>
int countKeeper=0;

void frontstring(char str[],char c){ // Define function for adding a character to the front of a string
    int len_t=strlen(str);
    for(int i=len_t;i>=0;i--){
        str[i+1]=str[i];
    }
    str[0]=c;
}

void frontremovestring(char str[]){ // Define function for removing the first character of a string
    int len_t=strlen(str);
    for(int i=0;i<len_t;i++){
        str[i]=str[i+1];
    }
}

void lastremovestring(char str[]){ // Define function for removing the last character of a string
    str[strlen(str)-1]='\0';
}

char * addbefore(dict * T,char str[]){ // Define function for adding a character before a string to form a new string
    char * before = (char *)malloc(befaf_size*(sizeof(char))); // Allocate memory for the new string
    before[0]='\0'; // Initialize new string as empty
    for(char c='a';c<='z';c++){ // Iterate through all characters in the alphabet
        frontstring(str,c); // Add character to the front of the string
        if(triesearch(T,str)){ // Check if new string is in the dictionary
            addstring(before,c); // Add character to new string
        }
        frontremovestring(str); // Remove added character from original string
    }
    return before; // Return new string with added characters
}

char * addafter(dict * T,char str[]){ // Define function for adding a character after a string to form a new string
    char * tempAfter = (char *)malloc(befaf_size*(sizeof(char))); // Allocate memory for the new string
    tempAfter[0]='\0'; // Initialize new string as empty
    for(char c='a';c<='z';c++){ // Iterate through all characters in the alphabet
        addstring(str,c); // Add character to the end of the string
        if(triesearch(T,str)){ // Check if new string is in the dictionary
            addstring(tempAfter,c); // Add character to new string
        }
        lastremovestring(str); // Remove added character from original string
    }
    return tempAfter; // Return new string with added characters
}

struct arrofstr * anagrams(dict * T, char S[]){ // Define function for finding anagrams of a given string
    struct arrofstr * node =(struct arrofstr *)malloc(1000*sizeof(struct arrofstr)); // Allocate memory for struct to store anagrams
    strcpy(node[countKeeper].permu_str,"NULL"); // Initialize struct with NULL value
    char a[100];
    strcpy(a,S); // Copy input string to new variable
    int n = strlen(a);
	findPermutations(T,a, 0, n,node); // Call recursive function to find permutations of the string
    strcpy(node[countKeeper].permu_str,"NULL"); // Add NULL value to struct to mark the end of the array
    return node; // Return array of anagrams
}

bool SwapDecide(char str[], int start, int curr)
{
	for (int i = start; i < curr; i++)
		if (str[i] == str[curr])
			return 0;
	return 1;
}

void findPermutations(dict * T,char str[], int index, int n,struct arrofstr * node)
{
	if (index >= n) {
        if(triesearch(T,str)){
        strcpy(node[countKeeper].permu_str,str);
        countKeeper++;
		return;}
        return;
	}

	for (int i = index; i < n; i++) {

		bool check = SwapDecide(str, index, i);
		if (check) {

			char temp = str[index];
			str[index] = str[i];
			str[i] = temp;
			findPermutations(T,str, index + 1, n,node);

			temp = str[index];
			str[index] = str[i];
			str[i] = temp;
		}
	}
}

