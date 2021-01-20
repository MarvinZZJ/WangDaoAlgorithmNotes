/*
例题7.2	FatMouse' Trade	
http://acm.hdu.edu.cn/showproblem.php?pid=1009
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct JavaBean{
    double weight;
    double cost;
};

const int MAXN = 1000;

JavaBean arr[MAXN];

bool Compare(JavaBean x, JavaBean y){
    return (x.weight / x.cost) > (y.weight / y.cost);
}

int main(){
    int m, n;
    while(cin >> m >> n){
        if(m == -1 && n == -1){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i].weight >> arr[i].cost;
        }
        sort(arr, arr + n, Compare);
        double answer = 0;
        for(int i = 0; i < n; i++){
            if(m >= arr[i].cost){
                m -= arr[i].cost;
                answer += arr[i].weight;
            }
            else{
                double percent = m / arr[i].cost;
                answer += arr[i].weight * percent;
                break;
            }
        }
        printf("%.3f\n", answer);
    }
    return 0;
}
