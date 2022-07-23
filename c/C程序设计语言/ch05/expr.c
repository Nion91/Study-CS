#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000
#define STACKSIZE 1000

double stack[STACKSIZE];
double *ps = stack;

double atof(char *pc);
void push(double num);
double pop(void);

main(int argc, char *argv[]){
    char line[MAXLINE];
    int c;
    double op2;
    while (--argc > 0){
        if (isdigit(c = (*++argv)[0]) || (c == '.')){
            printf("argc: %s\n", *argv);
            push(atof(*argv));
        } else {
            printf("opa: %c\n", c);
            switch (c){
                case '+': 
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                default:
                    printf("Ivalid operator\n");
                    return -1;
            }
        }
    }
    printf("result: %g\n", pop());
    return 0;
}


double atof(char *pc){
    double res = 0.0;
    int n = 1;
    while(isdigit(*pc)){
        res = res * 10.0 + *pc - '0';
        pc++;
    }
    if (*pc == '.'){
        while (isdigit(*++pc)){
            res = res *10.0 + *pc - '0';
            n *= 10;
        }
        res /= n;
    }
    return res;
}

void push(double num){
    if (ps < stack + STACKSIZE){
        *ps++ = num;
    } else {
        printf("error: stack is full");
    }
}

double pop(void){
    if (ps > stack){
        return *--ps;
    } else {
        printf("error: stack is empty\n");
        return -1;
    }
}