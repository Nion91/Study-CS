#include <ctype.h>

double atof2(char s[]){
    int i, sign;
    double sum, power;

    for (i = 0; isspace(i); i++){   /* 跳过空值 */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;  /* 提取符号 */
    if (s[i]=='+' || s[i]=='-'){    /* 跳过符号 */
        i++;
    }

    for (sum = 0; isdigit(s[i]); i++){
        sum = sum * 10 + s[i] - '0';    /* 处理整数部分 */
    }

    if (s[i] == '.'){                   /* 处理小数部分 */
        i++;
        for (power = 1.0; isdigit(s[i]); i++){
            sum = sum * 10 + s[i] - '0';
            power *= 10.0;
        }
        sum /= power;
    }
    if (s[i]=='e' || s[i]=='E'){        /* 处理指数部分 */
        i++;
        if (s[i] == '-'){               /* 指数为负时 */
            i++;
            for (power = 0; isdigit(s[i]); i++){
                power = power * 10 + s[i] - '0';
            }
            while (power > 0){
                sum /= 10;
                power--;
            }
        } else {
            if (s[i] == '+'){           /* 指数为正时 */
                i++;
            }
            for (power = 0; isdigit(s[i]); i++){
                power = power * 10 + s[i] - '0';
            }
            while (power > 0){
                sum *= 10;
                power--;
            }
        }
    }

    return sign * sum;
}