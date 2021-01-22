/*
例题7.4	今年暑假不AC	
http://acm.hdu.edu.cn/showproblem.php?pid=2037
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct program{
    int beginTime;
    int endTime;
};

program arr[MAXN];

bool Compare(program x, program y){
    return x.endTime < y.endTime;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i].beginTime >> arr[i].endTime;
        }
        sort(arr, arr + n, Compare);
        int currentTime = 0, answer = 0;
        for(int i = 0; i < n; i++){
            if(currentTime <= arr[i].beginTime){
                currentTime = arr[i].endTime;
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
