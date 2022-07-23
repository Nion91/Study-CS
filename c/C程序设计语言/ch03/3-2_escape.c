#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void antiescape(char s[], char t[]);

main(){
    char s[MAXLINE], t[] = "world   ";
    escape(s, t);
    printf("%s\n", s);

    char t2[] = "world\thello\nhh";
    antiescape(s, t2);
    printf("%s\n", s);
    return 0;
}

/* escapge: 将t复制到s中，且将换行符等不可见字符替换为对应转义字符 */
void escape(char s[], char t[]){
    int i, j;
    i = j = 0;
    while((i < MAXLINE-1) && (t[j] != '\0')){
        switch (t[j]) {
            case '\n': s[i++] = '\\'; s[i++] = 'n';break;
            case '\t': s[i++] = '\\'; s[i++] = 't';break;
            case ' ': s[i++] = '\\'; s[i++] = 'b';break;
            default: s[i++] = t[j]; break; 
        }
        if (i == MAXLINE + 1){
            s[i-2] = '\0';
            break;
        }
        j++;
    }
    s[i] = '\0';
}


/* unescape: 功能同escape相反 */
void antiescape(char s[], char t[]){
    int i, j;
    i = j = 0;
    while(i<MAXLINE-1 && t[j]!='\0'){
        if (t[j] == '\\'){
            switch (t[j+1])
            {
            case 't': s[i] = '\t'; break;
            case 'n': s[i] = '\n'; break;
            case 'b': s[i] = '\b'; break;
            default: s[i++] = '\\'; s[i++] = t[j+1]; break;
            }
            j += 2;
            if (i == MAXLINE){
                s[i-1] = '\0';
                break;
            }
        } else {
            s[i++] = t[j++];
        }
    }
    s[i] = '\0';
    
}

