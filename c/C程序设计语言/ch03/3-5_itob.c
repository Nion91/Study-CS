#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);


main(){
    int n;
    char s[1000];
    n = -0xabcd;
    itob(n, s, 16);
    printf("%s\n", s);
    printf("%0x\n", n);

    itob(n, s, 8);
    printf("%s\n", s);
    printf("%o\n", n);
}

void itob(int n, char s[], int b){
    int i = 0, sign = n, val;
    do {
        val = abs(n % b);
        s[i++] = (val>=10) ? val-10+'A' : val+'0';
    } while((n /= b) != 0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[]){
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}