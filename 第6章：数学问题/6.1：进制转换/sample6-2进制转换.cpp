/*
例题6.2	进制转换（清华大学复试上机题）	
http://t.cn/AiCuoPRO
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string Divide(string num, int x){
    int remainder = 0;
    for(int i = 0; i < num.size(); i++){
        int current = remainder * 10 + num[i] - '0';
        num[i] = current / x + '0';
        remainder = current % x;
    }
    int pos = 0;
    while(num[pos] == '0'){
        pos++;
    }
    return num.substr(pos);
}

void PrintBinary(string num){
    vector<int> answer;
    while(num.size() != 0){
        answer.push_back((num[num.size() - 1] - '0') % 2);
        num = Divide(num, 2);
    }
    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i];
    }
    cout << endl;
    return;
}

int main(){
    string num;
    while(cin >> num){
        PrintBinary(num);
    }
    return 0;
}
