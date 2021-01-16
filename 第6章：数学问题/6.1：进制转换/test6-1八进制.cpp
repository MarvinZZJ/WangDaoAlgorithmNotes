/*
习题6.1	八进制（华中科技大学复试上机题）	
http://t.cn/AiCu0lHe
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char IntToChar(int n){
    if(n < 10){
        return n + '0';
    }
    else{
        return n - 10 + 'A';
    }
}

//  //10进制num转换成为x进制,并输出八进制数
void ConvertAndPrint(int num, int x){
    vector<char> answer;
    if(num == 0){
        answer.push_back('0');
    }
    else{
        while(num != 0){
            answer.push_back(IntToChar(num % x));
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
    int num;
    while(scanf("%d", &num) != EOF){
        ConvertAndPrint(num, 8);
    }
    return 0;
}
