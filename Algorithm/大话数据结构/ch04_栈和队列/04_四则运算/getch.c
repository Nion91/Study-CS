#include <stdio.h>
#include <string.h>
#define MAXBUZZ 100     /* 缓存最大长度 */

static int buff[MAXBUZZ];
static int sp = 0;             /* 下一个空闲的buff位置 */

static int strbuff[MAXBUZZ];
static int fp = -1;            /* 加载字符串时用到的下标 */


/* getch: 从缓存buff或输入流获取字符 */
int getch(void){
    if (fp>=0)
        return strbuff[fp++];
    else
        return (sp > 0) ? buff[--sp] : getchar();
}

/* ungetch: 将字符放回缓存buff */
void ungetch(int c){
    if (fp > 0){
        strbuff[--fp] = c;
    } else if (sp >= MAXBUZZ){
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


/* fillbuff: 把字符串s加载到buff中 */
void fillbuff(char *s){
    int i;
    for (i = 0; i < strlen(s); i++){
        strbuff[i] = s[i];
    }
    strbuff[i] =  EOF;
    fp = 0;
}

/* clearfill: 清空加载的字符串 */
void clearfill(void){
    fp = -1;
}

/* printfill: 打印加载的字符串 */
void printfill(void){
    printf("%s\n", strbuff);
}