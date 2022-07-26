#include "stack.h"
#define MAXWORD 100


void InfixToPostfix(char *s);
int getword(char *word, int limitlen);
int GetPriority(int c);
