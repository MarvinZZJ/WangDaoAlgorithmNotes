/*
习题6.5	最简真分数（北京大学复试上机题）	
http://t.cn/AiCua2g8
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int GCD(int a, int b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    else{
        return GCD(b, a % b);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int answer = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(GCD(arr[i], arr[j]) == 1){
                    answer++;
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
