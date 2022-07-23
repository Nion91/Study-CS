#include <stdio.h>
#include <ctype.h>

void itoa(int n, char s[]);

main(){
    char line[1000];
    itoa(12456525, line);
    printf("%s\n", line);

}

void itoa(int n, char s[]){
    int i;
    if (n < 0){
        s[0] = '-';
        n = -n; 
    }
    if (n / 10){
        itoa(n / 10, s);
    } 
    for (i = 0; isdigit(s[i]) || s[i]=='-'; i++){
        ;
    }
    s[i] = n % 10 + '0';
}