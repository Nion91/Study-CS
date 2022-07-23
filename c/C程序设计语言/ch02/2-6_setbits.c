#include <stdio.h>

int setbits(int x, int p, int n, int y);

main(){
    int x = 0x1234;
    int y = 0x1219;
    printf("%0x\n", setbits(x, 12, 8, y));
}

int setbits(int x, int p, int n, int y){
    int a = ~0 << p;
    int b = ~(~0 << (p-n));
    int r1 = x & ( a | b);
    int r2 = (y & ~(~0 << n)) << (p-n);

    return r1 | r2;
}