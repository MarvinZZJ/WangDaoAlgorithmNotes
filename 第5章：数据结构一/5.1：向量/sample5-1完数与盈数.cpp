/*
例题5.1	完数与盈数（清华大学复试上机题）	
http://t.cn/AiKEyQWW
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int sum(int n){
    int res = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            res += i;
        }
    }
    return res;
}

int main(){
    vector<int> numberE, numberG;
    for(int i = 2; i <= 60; i++){
        if(i == sum(i)){
            numberE.push_back(i);
        }
        else if(i < sum(i)){
            numberG.push_back(i);
        }
    }
    cout << "E:";
    for(int i = 0; i < numberE.size(); i++){
        cout << " " << numberE[i];
    }
    cout << endl;
    cout << "G:";
    for(int i = 0; i < numberG.size(); i++){
        cout << " " << numberG[i];
    }
    cout << endl;
    return 0;
}
