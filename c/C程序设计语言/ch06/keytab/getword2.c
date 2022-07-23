#include <stdio.h>
#include <ctype.h>

int getword2(char *word, int limitlen){
    int getch(void);
    void ungetch(int);
    char *w = word;
    int c, lastc;

    int is_anno = 0;
    
    while (1){
        c = getch();
        if (c == '/' && !is_anno){      /* 处理注释 */
            if ((c = getch()) == '/'){
                is_anno = 1;
            } else if (c == '*'){
                is_anno = 2;
            } else {
                ungetch(c);
                c = '/';
                break;
            }
        } else if (c == '\n' && is_anno == 1){
            is_anno = 0;
        } else if (c == '*' && is_anno == 2){
            if ((c = getch()) == '/'){
                is_anno = 0;
            } else {
                ungetch(c);
            }
        } else if (!isspace(c) && !is_anno){
            break;
        }
    }

    if (c != EOF){
        *w++ = c;
    }
    if (!isalpha(c) && c != '_' && c != '"'){
        *w = '\0';
        return c;
    }
    if (c == '"'){
        while (1){      /* 处理字符串常量 */
            if ((*w++ = getch()) == '"' && *(w-2) != '\\')
                break;
        }
    } else {
        for (; --limitlen > 0; w++){
            if (!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
        }
    }
    
    *w = '\0';

    return word[0];
}

