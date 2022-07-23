#include <stdio.h>

#define MAXLINE 1000
#define NORMAL  0   /* 正常状态 */
#define TEXT1   1   /* 处于字符串中 */
#define TEXT2   2   /* 处于单字符中 */
#define EXPLAN1 3   /* 处于注释//中 */
#define EXPLAN2 4   /* 处于注释/* */

int checkline(char line[], int lim);

main(){
    char line[MAXLINE];
    int res;
    while((res=checkline(line, MAXLINE)) != 0){
        if(res > 0){
            printf("%s", line);
        }
    }
    return 0;
}

int checkline(char s[], int lim){
    int c, lastc, i, j, status;
    char sign[MAXLINE];

    status = NORMAL;
    j = 0;
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        s[i] = c;
        if(status == TEXT1){
            if(c=='"' && lastc!='\\'){
                status = NORMAL;
            }
        } else if(status == TEXT2){
            if(c=='\'' && lastc!='\\'){
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
                status = TEXT1;
            } else if(c == '\''){
                status = TEXT2;
            } else if(c=='/' && lastc=='/'){
                status = EXPLAN1;
            } else if(c=='*' && lastc=='/'){
                status = EXPLAN2;
            } else if(c=='(' || c=='[' || c=='{'){
                sign[j] = c;
                j++;
            } else if(c==')'){
                if(j==0 || sign[j-1]!='('){
                    printf("Error: Check '()'\n");
                    return -1;
                }
                j--;
            } else if(c==']'){
                if(j==0 || sign[j-1]!='['){
                    printf("Error: Check '[]'\n");
                    return -1;
                }
                j--;
            } else if(c=='}'){
                if(j==0 || sign[j-1]!='{'){
                    printf("Error: Check '{}'\n");
                    return -1;
                }
                j--;
            } 
        }
        lastc = c;
    }

    if(j>0){
        printf("Error: Check %c\n", sign[j-1]);
        return -1;
    }

    if(c == '\n'){
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}
