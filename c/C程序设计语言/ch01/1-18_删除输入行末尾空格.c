#include <stdio.h>

#define MAXLINE 1000    /*  输入行的最大长度    */

int getline(char line[], int lim);

main(){
    char line[MAXLINE];

    while(getline(line, MAXLINE)>0){
        printf("%s", line);
    }

    return 0;
}

/*  getline：读入输入行，删除输入行末尾的空格和制表符，删除完全是空格的行   */
int getline(char s[], int lim){
    int c, i,j;
    for(i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        s[i] = c
        ;
    }
    /*从末尾检查空格和制表符*/
    if(c == '\n'){
        for(j = i-1; j>=0 && (s[j] == '\t' || s[j] == ' '); j--){
            ;
        }
        /*删除空行*/
        if(j == 0){
            s[0] = '\0';
            return 0;
        } 
        /*删除末尾空值*/
        else {
            s[j+1] = '\n';
            s[j+2] = '\0';
            return j+2;
        }
    } else {
        s[i] = '\0';
        return i;
    }
}
