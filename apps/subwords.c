#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <../util/dictutils.h>
#define Len_str 100


// This function returns the minimum character in a string and replaces it with an "&" character
char getMin(char *s)
{
    char sendChar;
    sendChar = 'z' + 1; // Initializing sendChar to a value greater than any lowercase ASCII character
    int iterator2 = 0;
    int len= strlen(s); // Calculating the length of the string
   
    for (size_t iterator1 = 0; iterator1 < len; iterator1++)
    {
        if (s[iterator1] != '&' && s[iterator1] < sendChar) // Checking if the current character is smaller than sendChar and not equal to "&"
        {
            sendChar = s[iterator1]; // Updating sendChar with the current character
            iterator2 = iterator1; // Keeping track of the index of the minimum character
        }
    }
    s[iterator2] = '&'; // Replacing the minimum character with "&"
    return sendChar; // Returning the minimum character
}


// This function takes a string and returns its sorted version
void sortedString(const char s1[], char *s2)
{
    int iterator2 = 0;
    char temp[Len_str];
    strcpy(temp, s1);
    for (int iterator1 = 0; s1[iterator1] != '\0'; iterator1++)
    {
        s2[iterator2] = getMin(temp); // Calling getMin() to get the minimum character and adding it to s2
        iterator2++;
    }
    return;
}

int main()
{
    dict *T;
    T=trieinit();

    T=loaddfltdict();
    int countStr=0;
    //listall(T);
    printf("\n \n\n");
    printf("Enter a lowercase string: ");
    char str[Len_str];
    scanf("%s", str);
    char str1[Len_str];
    sortedString(str, str1);
    int iterator1 = 0;
    int iterator2 = 0;
    while (str1[iterator2] != '\0')
    {
        char temp[Len_str];
        int w = 0;
        if (iterator2 >= 1 && str1[iterator2] != str1[iterator2 - 1])
        {
            for (int iterator3 = 0; str1[iterator3] != '\0'; iterator3++)
            {
                if (iterator3 != iterator2)
                {
                    temp[w++] = str1[iterator3];
                }
            }
            temp[w] = '\0';
            struct arrofstr *anagrams_node = anagrams(T, temp);
            while (strcmp(anagrams_node[iterator1].permu_str, "NULL") != 0)
            {
                printf("%s \n", anagrams_node[iterator1].permu_str);
                countStr++;
                iterator1++;
            }
           
        }
        if (iterator2 == 0)
        {
            for (int iterator3 = 1; str1[iterator3] != '\0'; iterator3++)
            {
                temp[w++] = str1[iterator3];
            }
            temp[w] = '\0';
           
            struct arrofstr *anagrams_node = anagrams(T, temp);
            while (strcmp(anagrams_node[iterator1].permu_str, "NULL") != 0)
            {
                printf("%s \n", anagrams_node[iterator1].permu_str);
                countStr++;
                iterator1++;
            }
           
        }
        iterator2++;
    }
    if(countStr!=0){
         printf("%d subwords found\n",countStr);
    }
   else{
    printf("No subwords found\n");
   }
   return 0;
}