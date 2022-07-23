#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa4(int n, char s[], int width);
void reverse(char s[]);

main(){
    int n = -15;
    char s[100];
    itoa4(n, s, 4);
    printf("%s\n", s);
}

void itoa4(int n, char s[], int width){
    int i = 0, sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);
    if (sign < 0){
        s[i++] = '-';
    }
    while(i < width){
        s[i++] = ' ';
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