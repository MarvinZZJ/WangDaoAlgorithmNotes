/*
习题2.1	与7无关的数（北京大学复试上机题）
http://t.cn/E9lOOZQ
*/

#include <iostream>
#include<cstdio>

using namespace std;

bool isRelatedTo7(int x){
    if(x % 7 == 0)
        return true;
    while(x){
        if(x % 10 == 7){
            return true;
        }
        x /= 10;
    }
    return false;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(!isRelatedTo7(i)){
                sum += i * i;
            }
        }
        printf("%d", sum);
    }
    return 0;
}
