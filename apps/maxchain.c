#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <../util/dictutils.h>

// Function to recursively find the maximum chain length and list of words
int maxchain_rec(dict *dictionary, char *s, int *maxLenNow, char **list)
{
    // Get the length of the current string
    int len_str = strlen(s);
    // Add the current string as a prefix and suffix to get two new strings
    char *b = strdup(addbefore(dictionary, s));
    char *af = strdup(addafter(dictionary, s));
    // Allocate memory for a new string that is one character longer than the current string
    char *new_str = (char *)malloc((len_str + 2) * sizeof(char));
    // Initialize variables to store the maximum length, the string with the maximum length, and a temporary length
    int ans = len_str, temp;
    char *ans_str;

    // If there are no words that can be made by adding to the prefix or suffix, return the length of the current string
    if (strlen(b) + strlen(af) == 0)
    {
        return len_str;
    }

    // Try adding each character in the prefix to the beginning of the current string and recursively find the maximum chain length
    strcpy(new_str + 1, s);
    int i = 0;
    while (i < strlen(b))
    {
        new_str[0] = b[i];
        int temp = maxchain_rec(dictionary, new_str, maxLenNow, list);
        if (temp > ans)
        {
            ans = temp;
            ans_str = strdup(new_str);
        }
        i++;
    }

    // Try adding each character in the suffix to the end of the current string and recursively find the maximum chain length
    strcpy(new_str, s);
    new_str[len_str + 1] = '\0';
    i = 0;
    while (i < strlen(af))
    {
        new_str[len_str] = af[i];
        int temp = maxchain_rec(dictionary, new_str, maxLenNow, list);
        if (temp > ans)
        {
            ans = temp;
            ans_str = strdup(new_str);
        }
        i++;
    }

    // If the maximum chain length found is greater than or equal to the current maximum length, update the maximum length and add the string to the list
    if (ans >= (*maxLenNow))
    {
        *maxLenNow = ans;
        list[strlen(ans_str)] = strdup(ans_str);
    }
    // Return the maximum chain length found
    return ans;
}

int main()
{
    // Load the default dictionary
    dict *dictionary = loaddfltdict();
    // Allocate memory for an array of strings
    char **strings = (char **)malloc(str_size * sizeof(char *));
    int i = 0;
    while (i < str_size)
    {
        strings[i] = NULL;
        i++;
    }
    // Initialize variables to store the maximum chain length and the maximum length found
    int max_len = 0;
    int maximum = maxchain_rec(dictionary, strdup(""), &max_len, strings);
    // Print the list of strings with the maximum length
    i = 1;
    while (i < maximum + 1)
    {
        printf("==> %s\n", strings[i]);
        i++;
    }
    return 0;
}
