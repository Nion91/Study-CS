#include <stdio.h>
#include <string.h>

void recur_reverse(char s[], int i);

main(){
    char line[] = "hello, world!";
    recur_reverse(line, 0);
    printf("%s\n", line);
}

void recur_reverse(char s[], int i){
    int j = strlen(s) - i - 1;
    char tmp;
    if (j > i){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        recur_reverse(s, ++i);
    }
}
