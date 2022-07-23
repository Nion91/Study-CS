#include <stdio.h>

int bitcount(unsigned x);

main(){
    printf("%d\n", bitcount(0x1234));
    printf("%d\n", bitcount(0xf007));
}

int bitcount(unsigned x){
    int b;
    for(b = 0; x != 0; x &= (x-1)){
        b++;
    }
    return b;
}
