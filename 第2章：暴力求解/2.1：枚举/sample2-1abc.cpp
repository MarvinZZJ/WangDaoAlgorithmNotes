/*
例题2.1	abc（清华大学复试上机题）	
http://t.cn/E9WMRTE
*/

#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            for(int c = 0; c <= 9; c++){
                if(100 * a + 110 * b + 12 * c == 532)
                    printf("%d %d %d\n", a, b, c);
            }
        }
    }
    return 0;
}
