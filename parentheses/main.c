#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFF BUFSIZ * 2

char stack[BUFF];
size_t len = 0;

bool check_closing(char par)
{
    size_t c = len;
    while (1) {
        if (stack[c] == '\0') {
            goto next;
        }
        if (stack[c] == par) {
            stack[c] = '\0';
            return true;
        } else {
            return false;
        }

    next:
        if (c == 0) {
            break;
        }
        --c;
    }
    return false;
}

bool isValid(char *s)
{
    memset(stack, 0, BUFF);

    char last_ch = '\0';
    while (*s != '\0') {
        switch (*s) {
        case '(':
        case '[':
        case '{':
            stack[len++] = *s;
            break;
        case ')':
            if (!check_closing('(')) {
                return false;
            }
            break;
        case ']':
            if (!check_closing('[')) {
                return false;
            }
            break;
        case '}':
            if (!check_closing('{')) {
                return false;
            }
            break;
        default:
            return false;
        }
        ++s;
    }

    for (int i = 0; i < len; ++i) {
        if (stack[i] != '\0') {
            return false;
        }
    }

    return true;
}

char *sample_1 = "{[()]}";

/* https://leetcode.com/problems/valid-parentheses/ */
int main(void)
{
    bool res = isValid(sample_1);
    printf("res: %d\n", res);
    return 0;
}
