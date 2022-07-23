#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000
int getline(char *line, int limitline);

main(int argc, char *argv[]){
    char line[MAXSIZE];

    if (argc != 2){
        printf("Error");
        return -1;
    } 

    while (getline(line, MAXSIZE) > 0){
        if (strstr(line, argv[1]) != NULL){
            printf("%s", line);
        }
    }
    return 0;
}

int getline(char *line, int limitline){
    int c, n = limitline;
    while (limitline-- > 1 && (c = getchar()) != EOF && c != '\n'){
        *line++ = c;
    }
    if (c == '\n'){
        *line++ = c;
    }
    *line = '\0';
    return n - limitline;
}