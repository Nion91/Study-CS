#include <stdio.h>
#include "HashTable.h"

main(){
    HashTable H;

    printf("\n==============================insert============================\n");
    InitHashTable(&H);

    int i;
    int a[] = {48, 37, 15, 16, 29, 56, 34, 47, 12, 25};

    for (i = 0; i < 10; i++)
        InsertHash(&H, a[i]);
    PrintHash(H);

    printf("\n==============================search============================\n");
    int addr;
    SearchHash(H, 20, &addr);
    SearchHash(H, 25, &addr);
    printf("addr: %d\n", addr);
}
