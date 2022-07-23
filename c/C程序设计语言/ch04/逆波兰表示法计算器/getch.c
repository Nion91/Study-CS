#include <stdio.h>
#include <string.h>
#define MAXBUZZ 100     /* 缓存最大长度 */

static int buff[MAXBUZZ];
static int sp = 0;             /* 下一个空闲的buff位置 */

int getch(void){
    return (sp > 0) ? buff[--sp] : getchar();
}

void ungetch(int c){
    if (sp >= MAXBUZZ){
        printf("error: buff is fullsize\n");
    } else {
        buff[sp++] = c;
    }
}


/* ungets: 将整个字符串压回输入中 */
void ungets(char s[]){
    int i;
    for (i = strlen(s) - 1; i >= 0; i--){
        ungetch(s[i]);
    }
}

