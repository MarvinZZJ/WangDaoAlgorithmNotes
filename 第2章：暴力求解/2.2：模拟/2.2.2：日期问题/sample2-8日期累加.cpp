/*
例题2.8	日期累加（北京理工大学复试上机题）	
http://t.cn/E9Yw0Cr
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int months[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool IsLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysOfYear(int year){
    if(IsLeapYear(year)){
        return 366;
    }
    else{
        return 365;
    }
}

int main(){
    int year, month, day, number;
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--){
        scanf("%d%d%d%d", &year, &month, &day, &number);
        int row = IsLeapYear(year);
        for(int i = 0; i < month; i++){
            number += months[row][i];
        }
        number += day;
        while(daysOfYear(year) < number){
            number -= daysOfYear(year);
            year++;
        }
        month = 1;
        row = IsLeapYear(year);
        while(months[row][month] < number){
            number -= months[row][month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
