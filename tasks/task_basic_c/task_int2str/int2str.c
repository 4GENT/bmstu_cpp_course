#include "int2str.h"
#include <stdlib.h>
#include <stdio.h>

char* int2str(int num) {
    char* str = malloc(12 * sizeof(char));
    int i = 10;
    unsigned int abs_num = (num < 0) ? -num : num;
    str[11] = '\0';

    if (num == 0) {
        str[i--] = '0';
    } else {
        while (abs_num > 0) {
            str[i--] = (abs_num % 10) + '0';
            abs_num /= 10;
        }

        if (num < 0) {
            str[i--] = '-';
        }
    }

    return &str[i + 1];
}
