/*
习题6.2	又一版A+B（浙江大学复试上机题）	
http://t.cn/AiCuOSWv
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void ConvertAndPrint(unsigned int num, int x){
    vector<int> answer;
    if(num == 0){
        answer.push_back(0);
    }
    else{
        while(num){
            answer.push_back(num % x);
            num /= x;
        }
    }
    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i];
    }
    cout << endl;
    return;
}

int main(){
    int m;
    while(scanf("%d", &m) != EOF){
        if(m == 0){
            break;
        }
        unsigned int a, b;
        scanf("%d%d", &a, &b);
        ConvertAndPrint(a + b, m);
    }
    return 0;
}
