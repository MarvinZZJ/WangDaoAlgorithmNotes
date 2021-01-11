/*
例题2.6	今年的第几天？（清华大学复试上机题）	
http://t.cn/E9jXK5A
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool IsLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main(){
    int months[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int year, month, day;
    while(scanf("%d %d %d", &year, &month, &day) != EOF){
        int sum = 0;
        int row;
        if(IsLeapYear(year)){
            row = 1;
        }
        else{
            row = 0;
        }
        for(int i = 1; i < month; i++){
            sum += months[row][i];
        }
        sum += day;
        printf("%d\n", sum);
    }
    return 0;
}
