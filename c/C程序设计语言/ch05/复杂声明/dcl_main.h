#define MAXLEN 1000

enum {NAME, PARENS, BRACKETS};
int tokentype;
char token[MAXLEN];
char out[MAXLEN];
char name[MAXLEN];
char datatype[MAXLEN];

char bufftoken[MAXLEN];
int bufftokentype;
int buffflg;

void dcl(void);
void dirdcl(void);
int gettoken(void);
char getch(void);
void ungetch(char c);

void undcl(void);