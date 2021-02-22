/*
附加题7.3 Drying
http://poj.org/problem?id=3104
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 10;

int water[MAXN];

bool Judge(int n, int k, int time){
    int answer = 0;
    for(int i = n - 1; i >= 0; i--){
        if(water[i] > time){
            answer += ceil((water[i] - time) * 1.0 / (k - 1));
        }
    }
    if(time >= answer){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> water[i];
        }
        int k;
        cin >> k;
        sort(water, water +n);
        if(k == 1){
            cout << water[n - 1] << endl;
        }
        int minTime = 1, maxTime = water[n - 1];
        while(minTime <= maxTime){
            int mid = (maxTime - minTime) / 2 + minTime;
            if(Judge(n, k, mid)){
                maxTime = mid - 1;
            }
            else{
                minTime = mid + 1;
            }
        }
        cout << minTime << endl;
    }

    return 0;
}
