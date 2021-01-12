/*
习题3.6	打印极值点下标（北京大学复试上机题）	
http://t.cn/E9ehDw4
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 80 + 10;

int arr[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        if(arr[0] != arr[1]){
            printf("%d ", 0);
        }
        for(int i = 1; i < n - 1; i++){
            if((arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) || (arr[i - 1] > arr[i] && arr[i + 1] > arr[i])){
                printf("%d ", i);
            }
        }
        if(arr[n - 2] != arr[n - 1]){
            printf("%d", n - 1);
        }
        printf("\n");
    }
    return 0;
}
