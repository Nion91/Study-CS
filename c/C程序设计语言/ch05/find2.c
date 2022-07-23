#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000
int getline(char *line, int limitline);

main(int argc, char *argv[]){
    char line[MAXSIZE];
    int nlines = 0;
    int c, except, number, found;
    except = number = found =0;
    while (--argc > 0 && (*++argv)[0] == '-'){
        while (c = *++argv[0]){
            switch (c){
                case 'e': except = 1; break;
                case 'n': number = 1; break;
                default : 
                    printf("Ivalid commond\n");
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1){
        printf("usage: find -e -n pattern\n");
    } else {
        while (getline(line, MAXSIZE) > 0){
            nlines++;
            printf("argv: %s\n", *argv);
            if ((strstr(line, *argv) != NULL) != except){
                found++;
                if (number){
                    printf("%d: ", nlines);
                }
                printf("%s", line);
            }
        }
    }
    return found;
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