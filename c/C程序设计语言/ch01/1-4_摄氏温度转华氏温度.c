#include <stdio.h>

main(){
    int celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 150;
    step = 10;

    celsius = lower;
    while (celsius <= upper){
        fahr = 32 + celsius * 1.8;
        printf("%3d %6d\n", celsius, fahr);
        celsius = celsius + step;
    }
}
