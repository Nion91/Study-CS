#include <stdio.h>

#define LOWER   0      /* 表的下限 */
#define UPPER   300    /* 表的上限 */
#define STEP    20     /* 步长 */

main(){
    int fahr;
    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP){
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}