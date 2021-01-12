/*
例题3.4	找x（哈尔滨工业大学复试上机题）	
http://t.cn/E9gHFnS
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200;

int arr[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int x;
        int result = -1;
        scanf("%d", &x);
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                result = i;
                break;
            }
        }
        printf("%d", result);
    }
    return 0;
}
