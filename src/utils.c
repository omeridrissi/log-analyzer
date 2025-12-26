#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long count_string(const char *needle, const char *haystack) {
    long count = 0;
    const char *tmp = haystack;
    while ((tmp = strstr(tmp, needle))) {
        count++;
        tmp++;
    }
    return count;
}
