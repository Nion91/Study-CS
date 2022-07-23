#include <stdio.h>

#define MINLEN 10   /* 可打印的最小长度 */
#define MAXLEN 1000 /* 输入行最大长度   */

int getline(char line[], int maxlen);
void copy(char to[], char from[]);

main(){
    int len;
    char line[MAXLEN];

    while((len=getline(line,MAXLEN))>0){
        if(len >= MINLEN){
            printf("%s", line);
        }
    }

    return 0;
}

/* getline:读取输入并返回输入长度 */
int getline(char line[], int maxlen){
    int c, i;
    for(i = 0; i<maxlen-1 && (c=getchar())!=EOF && c!='\n'; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;
    for(i = 0; (to[i]=from[i])!='\0'; i++)
        ;
}