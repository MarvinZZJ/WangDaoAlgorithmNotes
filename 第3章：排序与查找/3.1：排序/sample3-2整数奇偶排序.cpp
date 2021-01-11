/*
习题3.2	整数奇偶排序（北京大学复试上机题）	
http://t.cn/E9glPvp
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool Compare(int x1, int x2){
    if(x1 % 2 == 0 && x2 % 2 == 0){
        return x1 < x2;
    }
    else if(x1 % 2 == 1 && x2 % 2 == 1){
        return x1 > x2;
    }
    else{
        return (x1 % 2 > x2 % 2);
    }
}

int main(){
    int arr[10];
    while(scanf("%d", &arr[0]) != EOF){
        for(int i = 1; i < 10; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + 10, Compare);
        for(int i = 0; i < 10; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
