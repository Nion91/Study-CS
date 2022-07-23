#include <stdio.h>

#define MAXLINE 1000

int revline(char line[], int maxline);

main(){
    char line[MAXLINE];
    while(revline(line, MAXLINE) > 0){
        printf("%s\n", line);
    }
}

/* revline: 将输入行中的字符顺序逆序存入s中 */
int revline(char s[], int lim){
    int c, i, len;
    char line[lim];

    for(i = 0; i<lim-1 && (c=getchar())!=EOF; i++){
        line[i] = c;
    }
    len=i;
    for(i = 0; i < len; i++){
        s[i] = line[len-i-1];
    }
    s[len] = '\0';
    return len;
}