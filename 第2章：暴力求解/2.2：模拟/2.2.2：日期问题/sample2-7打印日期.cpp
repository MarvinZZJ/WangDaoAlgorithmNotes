/*
例题2.7	打印日期（华中科技大学复试上机题）
http://t.cn/E9YP2a8
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool isLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

const int months[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
                           
int main(){
    int year, month, day, sum;
    while(scanf("%d %d", &year, &sum) != EOF){
        int row = isLeapYear(year);
        month = 1;
        int i = 1;
        while(sum > months[row][i]){
            month++;
            sum -= months[row][i++];
        }
        day = sum;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
