#include "int2str.h"
#include <limits.h>
#include <stdlib.h>

char* int2str(int num) {
    char* str = (char*)malloc(12 * sizeof(char));
    int i = 10;
    int isNegative = 0;

    str[11] = '\0';

    if (num == 0) {
        str[i] = '0';
        return &str[i];
    }

    if (num < 0) {
        isNegative = 1;
        if (num == INT_MIN) {
            num = -(num + 1);
            str[i--] = (num % 10) + 1 + '0';
            num /= 10;
        } else {
            num = -num;
        }
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
