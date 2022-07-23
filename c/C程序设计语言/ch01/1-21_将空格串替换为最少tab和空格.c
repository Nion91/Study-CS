#include <stdio.h>

#define TABWIDTH 8  /* tab占据的空格数量    */
#define MAXLINE 1000

int blank_to_tab(char line[], int lim);
void printstr(char s[]);

main(){
    char line[MAXLINE];
    while(blank_to_tab(line,MAXLINE) > 0){
        printf("%s", line);
        printstr(line);
    }
    return 0;
}


int blank_to_tab(char s[], int lim){
    int c, i, len, status;
    int nt, nb, j;
    
    status = 0;
    len = 0;
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        /*记录连续空格数量*/
        if(c == ' '){
            len++;
            if(status == 0){
                status = 1;
            }
        } else {
            /*前一个字符不是空格*/
            if(status == 0){
                s[i] = c;
            } 
            /*前一个字符是空格*/
            else {
                status = 0;
                if(len == 1){
                    s[i] = c;
                } else {
                    nt = i/TABWIDTH - (i-len)/TABWIDTH; /*tab数量*/
                    nb = i - nt*TABWIDTH;               /*空格数量*/
                    i = i - len;
                    for(j = 1; j <= nt; j++){
                        s[i] = '\t';
                        i++;
                    }
                    for(j = 1; j <= nb; j++){
                        s[i] = ' ';
                        i++;
                    }
                    
                    s[i] = c;
                }
                len = 0;
            }
        }
    }

    if(c == '\n'){
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}


void printstr(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            printf("\\b");
        } else if(s[i] == '\t'){
            printf("\\t");
        } else {
            putchar(s[i]);
        }
    }
}