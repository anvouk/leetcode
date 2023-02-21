#include <stdio.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    // Set the initial values for the prefix string and its size
    static char prefix[BUFSIZ];
    memset(prefix, 0, BUFSIZ);
    size_t sz = 0;

    // Get the maximum length of the strings in the input array
    size_t max = 0;
    for (size_t i = 0; i < strsSize; ++i) {
        size_t new_max = strlen(strs[i]);
        if (new_max > max) {
            max = new_max;
        }
    }

    // If the maximum length is 0, return an empty string
    if (max == 0) {
        return "";
    }

    // Iterate over the characters in each string and compare them
    char current;
    for (size_t c = 0; c < max; ++c) {
        for (size_t i = 0; i < strsSize; ++i) {
            char ch = strs[i][c];
            if (i == 0) {
                current = ch;
                continue;
            }

            // If the characters are not the same, return the current prefix
            if (current != ch) {
                goto done;
            }
        }

        // If all the characters are the same, add the current character to the prefix
        prefix[sz++] = current;
    }

done:
    // Add a null terminator to the prefix string and return it
    prefix[++sz] = '\0';
    return prefix;
}

// Define some sample input strings
char *sample_1[] = { "flower", "flow", "flight" };
char *sample_2[] = { "" };

/* https://leetcode.com/problems/longest-common-prefix/ */
int main(void)
{
    // Get the longest common prefix for the sample inputs
    const char *str1 = longestCommonPrefix(sample_1, 3);
    printf("longest: '%s'\n", str1);
    const char *str2 = longestCommonPrefix(sample_2, 1);
    printf("longest: '%s'\n", str2);
    return 0;
}
