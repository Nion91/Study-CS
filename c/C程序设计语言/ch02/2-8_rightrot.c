#include <stdio.h>

int rightrot(int x, int n);

main(){
    printf("%0x\n", rightrot(0x1237, 4));
    printf("%0x\n", rightrot(0x12f1, 16));
}

int rightrot(int x, int n){
    int p1 = x >> n;
    unsigned int p2;
    int i, tmp;
    p2 = 0;
    for(i = 1; i <= n; i++){
        if(((x>>(i-1)) & 1) == 1){
            tmp = ~(~0u >> 1);
        } else {
            tmp = 0;
        }
        p2 = (p2 >> 1) | tmp;
    }
    return p1 | p2;
}

