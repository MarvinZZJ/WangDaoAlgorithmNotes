/*
习题2.8	日期类（北京理工大学复试上机题）	
http://t.cn/E9RJUp4
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--){
        int year, month, day;
        scanf("%d%d%d", &year, &month, &day);
        if(++day > months[month]){
            month++;
            day = 1;
        }
        if(month > 12){
            year++;
            month = 1;
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
