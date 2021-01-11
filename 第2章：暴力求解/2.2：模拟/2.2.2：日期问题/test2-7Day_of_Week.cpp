/*
习题2.7	Day of Week（清华大学复试上机题）	
http://t.cn/E9YZLbi
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int months[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

string monthName[13] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
};

string weekName[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
};

bool IsLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int DaysOfYear(int year){
    return (IsLeapYear(year) ?  366 : 365);
}

int Number(int year, int month, int day){
    int num = 0;
    for(int i = 1; i < year; i++){
        num += DaysOfYear(i);
    }
    int row = IsLeapYear(year);
    for(int i = 1; i < month; i++){
        num += months[row][i];
    }
    num += day;
    return num;
}

int main(){
    int year, month, day;
    string monthInput;
    while(cin >> day >> monthInput >> year){
        for(int i = 1; i <= 12; i++){
            if(monthInput == monthName[i]){
                month = i;
                break;
            }
        }
        int num = Number(year, month, day);
        cout << weekName[num % 7] << endl;
    }
    return 0;
}
