/*
例题8.4	二叉树（北京大学复试上机题）	
http://t.cn/Ai0Ke6I0
*/

#include <iostream>
#include <cstdio>

using namespace std;

int CountNodes(int m, int n){
    if(m > n){
        return 0;
    }
    else{
        return CountNodes(m * 2, n) + CountNodes(m * 2 + 1, n) + 1;
    }
}

int main(){
    int m, n;
    while(cin >> m >> n){
        if(m == 0 && n == 0){
            break;
        }
        cout << CountNodes(m, n) << endl;
    }
    return 0;
}
