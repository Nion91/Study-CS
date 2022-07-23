#include <stdio.h>

static int daytab[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day){
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (year <= 0 || month <= 0 || month > 12 || day <=0 || day > daytab[leap][month-1]){
        printf("error\n");
        return -1;
    }
    for (i = 0; i < month-1; i++){
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *mp, int *dp){
    int i, leap;
    leap = (year%4 == 0 && year%100 !=0) || year%400 == 0;
    if (year <= 0 || yearday > (365+leap)){
        printf("error\n");
        return;
    }
    for (i = 0; yearday - daytab[leap][i] >0; i++){
        yearday -= daytab[leap][i];
    }
    *mp = i+1;
    *dp = yearday;
}


int day_of_month2(int year, int month, int day){
    int *p, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    p = daytab[leap];
    if (year <= 0 || month <= 0 || month > 12 || day <=0 || day > daytab[leap][month-1]){
        printf("error\n");
        return -1;
    }
    
    while (month-- > 1){
        day += *p++;
    }
    return day;
}


void month_day2(int year, int yearday, int *mp, int *dp){
    int leap;
    leap = (year%4 == 0 && year%100 !=0) || year%400 == 0;
    if (year <= 0 || yearday > (365+leap)){
        printf("error\n");
        return;
    }
    mp = daytab[leap];
    while (yearday > *mp){
        yearday -= *mp++;
    }
    *dp = yearday;
}