#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/function.h"

char *str_replace(char *str, char *search, char *replace) {
    char *p = str;
    char *s = strstr(p, search);
    char *result = NULL;
    int len = 0;
    int search_len = strlen(search);
    int replace_len = strlen(replace);
    while (s) {
        len += s - p;
        len += replace_len;
        p = s + search_len;
        s = strstr(p, search);
    }
    len += strlen(p);
    result = (char *) malloc(len + 1);
    p = result;
    s = strstr(str, search);
    while (s) {
        p = strncpy(p, str, s - str);
        p += s - str;
        p = strcpy(p, replace);
        p += replace_len;
        str = s + search_len;
        s = strstr(str, search);
    }
    strcpy(p, str);
    return result;
}

void start()
{
    char *str = "Hello World!";
    char *search = "World";
    char *replace = "World!";
    char *result = str_replace(str, search, replace);
    printf("%s\n", result);
    free(result);
}