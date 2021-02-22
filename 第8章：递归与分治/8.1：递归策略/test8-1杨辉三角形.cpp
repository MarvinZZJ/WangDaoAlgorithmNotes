/*
习题8.1	杨辉三角形（西北工业大学复试上机题）	
http://t.cn/Ai0KcLRI
*/

#include <iostream>
#include <cstdio>

using namespace std;

int YangHui(int i, int j){
    if(i == j || j == 1){
        return 1;
    }
    else{
        return YangHui(i - 1, j - 1) + YangHui(i - 1, j);
    }
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(i != j){
                    cout << YangHui(i, j) << " ";
                }
                else{
                    cout << YangHui(i, j) << endl;
                }
            }
        }
    }
    return 0;
}
