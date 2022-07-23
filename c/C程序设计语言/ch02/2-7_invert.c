#include <stdio.h>

int invert(int x, int p, int n);
main(){
    int x = 0x10f4;

    printf("%0x\n", invert(x, 12, 8));

    return 0;
}

int invert(int x, int p, int n){
    int a = (~0 << p) | ~(~0 << (p-n));
    int p1 = a & x;
    int p2 = ~a & ~x;
    return p1 | p2;
}