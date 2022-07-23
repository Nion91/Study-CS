#include <stdio.h>

#define swap(t,x,y) {t tmp; tmp = x; x = y; y = tmp;}

main(){
    int x = 1, y = 2;
    swap(int, x, y);
    printf("%d, %d\n", x, y);
    return 0;
}