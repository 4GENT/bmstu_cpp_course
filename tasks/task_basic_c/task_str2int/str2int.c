#include <assert.h>
#include <stdio.h>

const int max = 2147483647;
const int min = -2147483648;

int is_space(char c) {
    return c == ' ';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int str2int(const char *str) {
    int sign = 1;
    int result = 0;

    assert(str != NULL && *str != '\0');

    while (is_space(*str)) {
        str++;
    }

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    assert(*str != '\0');

    while (is_digit(*str)) {
        int digit = *str - '0';

        if (sign == 1 && (result > (max - digit) / 10)) {
            assert(0);
        }
        if (sign == -1 && (result > (min - digit) / 10)) {
            assert(0);
        }

        result = result * 10 + digit;
        str++;
    }

    return sign * result;
}
