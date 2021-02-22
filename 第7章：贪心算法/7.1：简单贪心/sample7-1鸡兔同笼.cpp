/*
例题7.1	鸡兔同笼（北京大学复试上机题）	
http://t.cn/E9ewERU
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a;
    while(scanf("%d", &a) != EOF){
        if(a % 2 == 0){
            int minimal, maximal;
            minimal = a / 4 + (a % 4) / 2;
            maximal = a / 2; 
            printf("%d %d\n", minimal, maximal);           
        }
        else{
            printf("0 0\n");
        }
    }
    return 0;
}
