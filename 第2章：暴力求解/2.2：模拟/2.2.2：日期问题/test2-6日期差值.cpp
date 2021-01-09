/*
习题2.6	日期差值（上海交通大学复试上机题）	
http://t.cn/E9Yz0LE
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int months[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool IsLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysOfYear(int year){
    return (IsLeapYear(year) ? 366 : 365);
}

// 用于计算year-month-day与baseYear-01-01两个日期的差值(天数包括两个日期本身)。
int differentiate(int baseYear, int year, int month, int day){
    int num = 0;
    for(int i = baseYear; i < year; i++){
        num += daysOfYear(i);
    }
    int row = IsLeapYear(year);
    for(int i = 1; i < month; i++){
        num += months[row][i];
    }
    num += day;
    return num;
}

int main(){
    int year1, month1, day1;
    int year2, month2, day2;
    while(scanf("%04d%02d%02d", &year1, &month1, &day1) != EOF){
        scanf("%04d%02d%02d", &year2, &month2, &day2);
        int baseYear = (year1 > year2 ? year2 : year1);
        int num1 = differentiate(baseYear, year1, month1, day1);
        int num2 = differentiate(baseYear, year2, month2, day2);
        printf("%d\n", abs(num1 - num2) + 1);
    }
    return 0;
}
