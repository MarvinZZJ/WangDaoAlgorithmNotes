/*
例题6.7	素数判定（哈尔滨工业大学复试上机题）	
http://t.cn/AiCuWE0Q
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrimeNum(int num){
    if(num <= 1){
        return false;
    }
    else{
        int bound = sqrt(num);
        for(int i = 2; i <= bound; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    int num;
    while(scanf("%d", &num) != EOF){
        if(isPrimeNum(num)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}
