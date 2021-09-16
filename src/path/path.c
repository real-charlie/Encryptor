#include <malloc.h>
#include <string.h>
#include "path.h"

int is_hidden_file(const char *path) {
    if (*(file_name(path)) == '.')
        return 1;
    return 0;
}

/*
 * returns file name of an absolute path
 * */
char *file_name(const char *path) {
    int i = 0;
    size_t len = strlen(path);
    char *current = malloc(len);
    while (*(path + i) != '\0') {
        char each = *(path + i++);
        if (each == '/')
            memset(current, 0, len);
        else
            strncat(current, &each, 1);
    }
    return current;
}
