#include <stdio.h>

#define MAXLINE 1000    /* 输入行最大长度   */
#define LINEWIDTH 20    /* 设定输出行单行长度 */


int cut_line(char line[], int lim, int width);

main(){
    char line[MAXLINE];
    while(cut_line(line, MAXLINE, LINEWIDTH) > 0){
        printf("%s", line);
    }
    return 0;
}

int cut_line(char s[], int lim, int width){
    int c, i, linecount, movecount;

    linecount = 0;
    movecount = 0;
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        if(linecount <= width){
            s[i] = c;
            linecount++;
        } else {
            linecount = 0;
            if((c==' ' || c=='\t') && (s[i-1]!=' ' && s[i-1]!='\t')){
                s[i] = '\n';
                i++;
                s[i] = c;
                linecount++;
            } else {
                while(s[i-1]!=' ' && s[i-1]!='\t'){
                    s[i] = s[i-1];
                    i--;
                    movecount++;
                }
                while(s[i-1]==' ' || s[i-1]=='\t'){
                    s[i] = s[i-1];
                    i--;
                    movecount++;
                }
                s[i] = '\n';
                i = i + movecount + 1;
                s[i] = c;
                linecount = movecount + 1;
                movecount = 0;
            }
        }
    }
    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}