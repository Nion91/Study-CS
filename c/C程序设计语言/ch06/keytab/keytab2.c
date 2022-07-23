#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEY (sizeof keytab / sizeof keytab[0])

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0}
};


int getword(char *, int);
struct key *binsearch(char *word, struct key tab[], int size);

main(){
    char word[MAXWORD];
    struct key *pk;

    while (getword(word, MAXWORD) != EOF){
        if (pk = binsearch(word, keytab, NKEY)){
            pk->count++;
        }
    }

    for (pk = keytab; pk < keytab + NKEY; pk++){
        printf("%s: %d\n", pk->word, pk->count);
    }
    return 0;
}


struct key *binsearch(char *word, struct key tab[], int size){
    struct key *low, *high, *mid;
    int cond;
    low = tab;
    high = tab + size - 1;
    while (low <= high){
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) > 0){
            low = mid + 1;
        } else if (cond < 0){
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return NULL;
}
