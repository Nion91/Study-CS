#define MAXLINES 5000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*cmpf)(void *, void *));
int numcmp(char *s1, char *s2);
int strcmp2(char *s1, char *s2);
int confined_strcmp(char *s1, char *s2);

int getline(char *p, int limitlen);
char * alloc(int n);
void afree(char *pa);
void swap(void *s[], int i, int j);
void reverse(void *v[], int nlines);