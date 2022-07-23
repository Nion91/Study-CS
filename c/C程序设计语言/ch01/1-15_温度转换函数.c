#include <stdio.h>

float fahr_to_celsius(int fahr);

main(){
    int fahr;
    float celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step =20;

    for(fahr = lower; fahr <= upper; fahr+=20){
        printf("%3d %6.1f\n", fahr, fahr_to_celsius(fahr));
    }
    return 0;
}

float fahr_to_celsius(int fahr){
    return (5.0/9.0)*(fahr-32);
}