#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Convert a string to an uint8 or return error.
 * @note Does not check if input string is made only of valid numbers but checks
 * for leading zeros, which are treated as an error.
 * @param str Valid number as string.
 * @return -1 on error, a num castable to uint8 otherwise.
 */
static int strtou8(const char *str)
{
    if (strlen(str) == 0) {
        return -1;
    }
    // no leading zeros are allowed.
    if (*str == '0' && *(str + 1) != '\0') {
        return -1;
    }

    char len = (char)strlen(str);
    int res = 0;
    int pos = 1;
    for (int i = 0; i < len - 1; ++i) {
        pos *= 10;
    }
    for (const char *c = str; *c != '\0'; ++c, pos /= 10) {
        res += (*c - '0') * pos;
    }
    if (res < 0 || res > 255) {
        return -1;
    }
    return res;
}

static bool validateIpv4(const char *queryIP)
{
    char ip[4][4] = { 0 };
    char ip_num_idx = 0;
    char ip_num_str_idx = 0;
    for (const char *c = queryIP; *c != '\0'; ++c) {
        if (*c == '.') {
            ++ip_num_idx;
            ip_num_str_idx = 0;

            // too many dots: invalid ipv4
            if (ip_num_idx > 3) {
                return false;
            }
            continue;
        }
        // not a digit other than dots: invalid ipv4
        if (!isdigit(*c)) {
            return false;
        }

        // u8 biggest char count is (255): invalid ipv4 otherwise.
        if (ip_num_str_idx >= 3) {
            return false;
        }

        ip[ip_num_idx][ip_num_str_idx++] = *c;
    }

    for (char i = 0; i < 4; ++i) {
        if (strtou8(ip[i]) == -1) {
            return false;
        }
    }
    return true;
}

static bool isHex(char ch)
{
    if (isdigit(ch)) {
        return true;
    }

    switch (ch) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        return true;
    default:
        return false;
    }
}

static bool validateIpv6(const char *queryIP)
{
    char ip[8][5] = { 0 };
    char ip_num_idx = 0;
    char ip_num_str_idx = 0;
    for (const char *c = queryIP; *c != '\0'; ++c) {
        if (*c == ':') {
            ++ip_num_idx;
            ip_num_str_idx = 0;

            // too many dots: invalid ipv6
            if (ip_num_idx > 7) {
                return false;
            }
            continue;
        }
        // not a digit other than dots: invalid ipv4
        if (!isHex(*c)) {
            return false;
        }

        // too many chars for num: invalid ipv4 otherwise.
        if (ip_num_str_idx >= 4) {
            return false;
        }

        ip[ip_num_idx][ip_num_str_idx++] = *c;
    }

    for (char i = 0; i < 8; ++i) {
        if (strlen(ip[i]) < 1) {
            return false;
        }
    }
    return true;
}

char *validIPAddress(char *queryIP)
{
    for (char *c = queryIP; *c != '\0'; ++c) {
        switch (*c) {
        case '.':
            if (validateIpv4(queryIP)) {
                return "IPv4";
            }
            return "Neither";
        case ':':
            if (validateIpv6(queryIP)) {
                return "IPv6";
            }
            return "Neither";
        }
    }
    return "Neither";
}

static void test(const char *ip)
{
    printf("ip: %-40s | res: %s\n", ip, validIPAddress(ip));
}

/* https://leetcode.com/problems/validate-ip-address/ */
int main(void)
{
    test("1.0.1.");
    test("192.168.30.0");
    test("192.168.01.1");
    test("192.168.01.");
    test("0.168.30.1");
    test("192.101.30.1");
    test("192.1013.30.1");
    test("192.101.30.1422");
    test("192.101..142");

    test("2001:0db8:85a3:0:0:8A2E:0370:7334");
    test("2001:0db8:85a3::0:8A2E:0370:7334");
    return 0;
}
