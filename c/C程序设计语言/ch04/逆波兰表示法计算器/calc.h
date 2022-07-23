#pragma once
#define NUMBER   '0'    /* 标志获取了一个数字   */
#define IDENTIFY '1'    /* 标志获取了一串字符   */

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void printtop(void);
void copytop(void);
void swaptop(void);
void clearstack(void);
void deal_with_identify(char s[]);