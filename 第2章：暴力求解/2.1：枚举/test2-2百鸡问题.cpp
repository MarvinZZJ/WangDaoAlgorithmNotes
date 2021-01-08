/*
习题2.2	百鸡问题（北京哈尔滨工业大学复试上机题）
http://t.cn/E9ldhru
*/

#include <iostream>
#include<cstdio>

using namespace std;

// 法一：
int main()
{
    double money;
    while(scanf("%lf", &money) != EOF){
        for(int x = 0; x * 5 <= money; x++){
            for(int y = 0; x * 5 + y * 3 <= money; y++){
                for(int z = 0; x * 5 + y * 3 + z / 3.0 <= money; z++){
                    if(x + y + z == 100){
                        printf("x=%d,y=%d,z=%d\n", x, y ,z);
                    }
                }
            }
        }
    }
    return 0;
}

// 法二：
int main(){
    double n;
    while(scanf("%lf", &n) != EOF){
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100 - i; j++){
                int res = 100 - i - j;
                if(15 * i + 9 * j + res <= 3 * n){
                    printf("x=%d, y=%d, z=%d\n", i, j, res);
                }
            }
        }
    }
    return 0;
}
