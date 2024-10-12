#include "int2str.h"
#include <limits.h>

char* int2str(int num) {
    static char str[12];
    int i = 10;
    int isNegative = 0;

    str[11] = '\0';

    if (num == INT_MIN) {
        return "-2147483648";
    }
    if (num == INT_MAX) {
        return "2147483647";
    }

    if (num == 0) {
        str[i] = '0';
        return &str[i];
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0 && i >= 0) {
        str[i--] = (num % 10) + '0';
        num /= 10;
    }

    if (isNegative && i >= 0) {
        str[i--] = '-';
    }

    return &str[i + 1];
}
