#include <stdio.h>
#include <string.h>
#include <dicttype.h>

// This function loads the default dictionary from the file "DFLT_DICT"
dict *loaddfltdict()
{
    // Initialize a new empty dictionary
    dict *dflt_dict = trieinit();
    FILE *ptr;
    char str[50];

    // Open the "DFLT_DICT" file
    ptr = fopen("/home/somya/Documents/Sys/Systems_Assignment/dict/DFLT_DICT", "r");
    if (ptr == NULL) {
        printf("Can't open \n");
    }

    // Read each line from the file and insert it into the dictionary
    while (fgets(str, 50, ptr) != NULL){
        int w = strlen(str);
        str[w-1] = '\0'; // remove the newline character at the end of the string
        trieinsert(dflt_dict, str);
    }

    // Close the file and return the loaded dictionary
    fclose(ptr);
    return dflt_dict;
}

// This function loads a dictionary from a given file pointer
dict *loaddict(FILE *ptr)
{
    // Initialize a new empty dictionary
    dict *mdict = trieinit();
    char str[50];

    if (ptr == NULL) {
        printf("Can't Open\n");
    }

    // Read each line from the file and insert it into the dictionary
    while (fgets(str, 50, ptr) != NULL) {
        trieinsert(mdict, str);
    }

    // Close the file and return the loaded dictionary
    fclose(ptr);
    return mdict;
}
