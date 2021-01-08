/*
习题2.3	old bill（上海交通大学复试上机题）
http://t.cn/E9jqijR
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n, x, y, z;
    while(scanf("%d", &n) != EOF){
        scanf("%d %d %d", &x, &y, &z);
        bool notFind = true;
        int sum;
        int tempSum = x * 1000 + y * 100 + z *10;
        for(int left = 9; left > 0 && notFind; left--){
            for(int right = 9; right >=0 && notFind; right--){
                sum = tempSum + 10000 * left + right;
                if(sum % n == 0){
                    notFind = false;
                    printf("%d %d %d\n", left, right, sum / n);
                }
            }
        }
        if(notFind){
            printf("0\n");
        }
    }
    return 0;
}
