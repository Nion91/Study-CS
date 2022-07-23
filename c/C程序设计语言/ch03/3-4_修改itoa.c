#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

void itoa3(int n, char s[]);
void reverse(char s[]);
void itoa2(int n, char s[]);
main(){
    int n = INT_MIN;
    char s[100];
    itoa2(n, s);
    printf("%s\n", s);
}

void itoa3(int n, char s[]){
    int i, sign;
    unsigned x;
    if((sign = n) < 0){
        x = (n == INT_MIN) ? ((unsigned)INT_MAX) + 1 : -n; 
    } else {
        x = n;
    }
    
    i = 0;
    do {
        s[i++] = x % 10 +'0';
    } while((x /= 10) > 0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[]){
    int i, j, c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa2(int n, char s[]){
    int i = 0, sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while((n/=10) != 0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}