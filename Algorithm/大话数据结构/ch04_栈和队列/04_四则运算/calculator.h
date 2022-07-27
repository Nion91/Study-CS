#include "stack.h"
#define MAXWORD 100

void InfixToPostfix(char *s1, char *s2);
//void InfixToPostfix(char *s);
int GetPriority(int c);
int CalPostfix(char *s);
void OpCal(int c, Stack *sp);
int getword(char *word, int limitlen);
void fillbuff(char *s);
void clearfill(void);
void printfill(void);
int getch(void);
