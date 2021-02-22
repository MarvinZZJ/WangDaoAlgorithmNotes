/*
附加题7.4 Radar Installation
http://poj.org/problem?id=1328
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e3 + 10;

struct Interval{
    int right;
    int left;
};

Interval arr[MAXN];

bool Compare(Interval x, Interval y){
    return x.left < y.left;
}

int main(){
    int n, d;
    int caseNum = 1;
    while(cin >> n >> d){
        int flag = 1;
        if(n == 0 &&d == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            if(y > d){
                flag = 0;
                break;
            }
            else{
                arr[i].left = x - sqrt(d * d - y * y * 1.0);
                arr[i].right = x + sqrt(d * d - y * y * 1.0);
            }
        }
        if(flag == 0){
            cout << "Case "<< caseNum++ << ": -1" << endl;
            continue;
        }
        sort(arr, arr + n, Compare);
        int installLoc = arr[0].right;
        int answer = 0;
        for(int i = 1; i < n; i++){
            if(installLoc >= arr[i].left){
                if(installLoc > arr[i].right){
                    installLoc = arr[i].right;
                }
            }
            else{
                answer++;
                installLoc = arr[i].right;  // 设置下一个可能的安装地点
            }
        }
        answer++;
        cout << "Case "<< caseNum++ << ": " << answer << endl;
    }
    return 0;
}
