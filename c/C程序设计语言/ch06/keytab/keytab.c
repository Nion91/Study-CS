/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEY (sizeof keytab / sizeof keytab[0])
#define WORDLEN 1000

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0}
};

int getword(char *word, int limitlen);
int binsearch(char *word, struct key keytab[], int tablen);
int getword2(char *word, int limitlen);

main(){
    int n;
    char word[WORDLEN];
    
    while(getword2(word, WORDLEN) != EOF){
        if (isalpha(word[0]) && (n = binsearch(word, keytab, NKEY)) >= 0){
            keytab[n].count++;
        }
    }
    
    for (n = 0; n < NKEY; n++){
        printf("%s: %d\n", keytab[n].word, keytab[n].count);
    }

    return 0;
}


int binsearch(char *word, struct key keytab[], int tablen){
    int low, high, mid;
    int cond;
    low = 0;
    high = tablen - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) > 0){
            low = mid + 1;
        } else if (cond < 0){
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

*/

