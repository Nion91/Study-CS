#include <stdio.h>

#define MAXLINE 1000
#define NORMAL  0   /* 正常状态 */
#define TEXT    1   /* 处于字符串中 */
#define EXPLAN1 2   /* 处于注释//中 */
#define EXPLAN2 3   /* 处于注释/* */

int getline(char line[], int lim);

main(){
    char line[MAXLINE];
    while(getline(line, MAXLINE) > 0){
        printf("%s", line);
    }
    return 0;
}

int getline(char s[], int lim){
    int c, lastc, i, status;
    status = NORMAL;
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';){
        if(status == TEXT){
            s[i++] = c;
            if(c == '"' && lastc!='\\'){
                status = NORMAL;
            }
        } else if(status == EXPLAN1){
            ;
        } else if(status == EXPLAN2){
            if(c=='/' && lastc=='*'){
                status = NORMAL;
            }
        } else {
            if(c == '"'){
                s[i++] = c;
                status = TEXT;
            } else if(c == '/' && lastc == '/'){
                i--;
                status = EXPLAN1;
            } else if(c == '*' && lastc == '/'){
                i--;
                status = EXPLAN2;
            } else {
                s[i++] = c;
            }
        }
        lastc = c;
    }

    if(c == '\n'){
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}