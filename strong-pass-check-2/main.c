#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool isPermittedSpecial(char ch)
{
    switch (ch) {
    case '!':
    case '@':
    case '#':
    case '$':
    case '%':
    case '^':
    case '&':
    case '*':
    case '(':
    case ')':
    case '-':
    case '+':
        return true;
    default:
        return false;
    }
}

bool strongPasswordCheckerII(char *password)
{
    if (strlen(password) < 8) {
        return false;
    }

    char last_ch = '\0';

    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;
    for (const char *ch = password; *ch != '\0'; ++ch) {
        if (*ch == last_ch) {
            return false;
        }
        last_ch = *ch;
        if (islower(*ch)) {
            has_lower = true;
            continue;
        }
        if (isupper(*ch)) {
            has_upper = true;
            continue;
        }
        if (isdigit(*ch)) {
            has_digit = true;
            continue;
        }
        if (isPermittedSpecial(*ch)) {
            has_special = true;
            continue;
        }
    }

    return has_lower && has_upper && has_digit && has_special;
}

/* https://leetcode.com/problems/strong-password-checker-ii/ */
int main(void)
{
    printf("d: %d\n", strongPasswordCheckerII("IloveLe3tcode!"));
    return 0;
}
