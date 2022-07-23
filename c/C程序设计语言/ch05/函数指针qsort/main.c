#include <stdio.h>
#include <string.h>
#include "qsort_main.h"

char *lineptr[MAXLINES];

main(int argc, char *argv[]){
    int nlines;
    int number = 0, rev = 0, flat = 0, dia = 0;
    int (*cmpfunc)(void *, void *);

    if (argc > 1 && strcmp(argv[1], "-n") == 0){
        number = 1;
    }

    while (--argc > 0 && (*++argv)[0] == '-'){
        int i;
        for (i = 1; (*argv)[i] != '\0'; i++){
            switch ((*argv)[i]){
                case 'n': number = 1; break;
                case 'r': rev = 1; break;
                case 'f': flat = 1; break;
                case 'd': dia = 1; break;
                default: printf("Ivalid Para\n"); break;
            }
        }
    }

    if (number) {
        cmpfunc = (int (*)(void *, void *)) number;
    } else if (flat){
        cmpfunc = (int (*)(void *, void *)) strcmp2;
    } else if (dia){
        cmpfunc = (int (*)(void *, void *)) confined_strcmp;
    } else {
        cmpfunc = (int (*)(void *, void *)) strcmp;
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort((void **)lineptr, 0, nlines-1,cmpfunc);
        if (rev){
            reverse((void **) lineptr, nlines);
        }
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort.\n");
        return -1;
    }
}
