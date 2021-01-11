/*
习题2.9	Grading（浙江大学复试上机题）	
http://t.cn/E9rDPSq
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int p, t, g1, g2, g3, gj;
    while(scanf("%d%d%d%d%d%d", &p, &t, &g1, &g2, &g3, &gj) != EOF){
        int diff = abs(g1 - g2);
        float result;
        if(diff <= t){
            result = (g1 + g2) / 2.0;
        }
        else{
            int diff1 = abs(g1 - g3);
            int diff2 = abs(g2 - g3);
            if(diff1 <= t && diff2 <= t){
                result = max(max(g1, g3), g3);
            }
            else if(diff1 > t && diff2 > t){
                result = gj;
            }
            else{
                result = (diff1 < diff2 ? (g1 + g3) / 2.0 : (g2 + g3) / 2.0);
            }
        }
        printf("%.1f\n", result);
    }
    return 0;
}
