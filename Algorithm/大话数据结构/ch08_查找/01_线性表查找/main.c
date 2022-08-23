#include <stdio.h>
#include <stdlib.h>
#include "search.h"


main(){
    int arr[10];
    int i;

    printf("\n==============================sequential============================\n");
    for (i = 0; i < 10; i++)
        arr[i] = rand() % 100;
    
    printf("arr: ");
    for (i = 0; i < 9; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[9]);

    printf("find result: %d\n", Sequential_Search(arr, 10, 24));
    printf("find result: %d\n", Sequential_Search(arr, 10, 25));


    printf("\n==============================binary============================\n");
    for (i = 0; i < 10; i++)
        arr[i] = i;

    printf("find result: %d\n", Binary_Search(arr, 10, 2));
    printf("find result: %d\n", Binary_Search(arr, 10, 11));


    printf("\n==============================interpolation============================\n");
    for (i = 0; i < 10; i++)
        arr[i] = i;

    printf("find result: %d\n", Interpolation_Search(arr, 10, 2));
    printf("find result: %d\n", Interpolation_Search(arr, 10, 11));


    printf("\n==============================fibonacci============================\n");
    for (i = 0; i < 10; i++)
        arr[i] = i;

    printf("find result: %d\n", Fibonacci_Search(arr, 10, 2));
    printf("find result: %d\n", Fibonacci_Search(arr, 10, 11));
}

