/*
例题8.2	汉诺塔Ⅲ	
http://acm.hdu.edu.cn/showproblem.php?pid=2064
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long Hannoi(int n){
    if(n == 1){
        return 2;
    }
    else{
        return 3 * Hannoi(n - 1) + 2;
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << Hannoi(n) << endl;
    }
    return 0;
}
