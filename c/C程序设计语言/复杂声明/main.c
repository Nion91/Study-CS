#include <stdio.h>
#include <string.h>
#include "dcl_main.h"

/*dcl_main*/
main(){
    while (gettoken() != EOF){
        strcpy(datatype, token);
        while (gettoken() == NAME){
            strcat(datatype, " ");
            strcat(datatype, token);
        }
        strcpy(bufftoken, token);
        bufftokentype = tokentype;
        buffflg = 1;
        out[0] = '\0';
        dcl();
        if (tokentype != '\n'){
            printf("Error: should be '\\n'");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}


/*undcl_main
main(){
    buffflg = 0;
    while (gettoken() != EOF){
        strcpy(out, token);
        undcl();
        if (tokentype != '\n'){
            printf("Error: should be '\\n'");
        }
        printf("%s\n", out);
    }
}
*/
