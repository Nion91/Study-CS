#include <stdlib.h>
#include <ctype.h>

int numcmp(char *s1, char *s2){
    double d1, d2;
    d1 = atof(s1);
    d2 = atof(s2);
    if (d1 == d2){
        return 0;
    } else {
        return (d1 > d2) ? 1 : -1;
    }
}


int strcmp(char *s1, char *s2){
    while(*s1 == *s2){
        if (*s1 == '\0'){
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' || *s1 < *s2) ? -1 : 1;
}

int strcmp2(char *s1, char *s2){
    while(tolower(*s1) == tolower(*s2)){
        if (*s1 == '\0'){
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' || tolower(*s1) < tolower(*s2)) ? -1 : 1;
}

int confined_strcmp(char *s1, char *s2){
    char c1, c2;
    while (1){
        while (!isalnum(*s1) && *s1 != ' '){
            s1++;
        }
        while (!isalnum(*s2) && *s2 != ' '){
            s2++;
        }
        int flag = 0;
        c1 = flag ? tolower(*s1) : *s1;
        c2 = flag ? tolower(*s2) : *s2;
        if (c1 != c2){
            break;
        }

        if (c1 == '\0'){
            return 0;
        }
        
        s1++;
        s2++;
    }

    return (c1 == '\0' || c1 < c2) ? -1 : 1;
}