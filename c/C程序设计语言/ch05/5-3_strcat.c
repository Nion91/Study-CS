#include <stdio.h>

/* strcat:将t指向字符串复制到s指向的字符串尾部 */
void strcat2(char *s, char *t){
    while (*s){
        s++;
    }
    while(*s++ = *t++)
        ;
}