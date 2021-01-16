/*
例题6.3	十进制与二进制（清华大学复试上机题）	
http://t.cn/AiCuoHKg
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string Divide(string num, int x){
    int remainder = 0;
    for(int i = 0; i < num.size(); i++){
        int current = remainder * 10 + num[i] - '0';
        num[i] = current / 2 + '0';
        remainder = current % 2;
    }
    int pos = 0;
    while(num[pos] == '0'){
        pos++;
    }
    return num.substr(pos);
}

string Multiple(string num, int x){
    int carry = 0;
    for(int i = num.size() - 1; i >= 0; i--){
        int current = carry  + (num[i] - '0') * x;
        num[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry){
        num = "1" + num;
    }
    return num;
}

string Add(string num, int x){
    int carry = x;
    for(int i = num.size() - 1; i >= 0; i--){
        int current = carry + num[i] - '0';
        num[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry){
        num = "1" + num;
    }
    return num;
}

int main(){
    string num;
    while(cin >> num){
        vector<int> binary;
        while(num.size() != 0){
            int last = num[num.size() - 1] - '0';
            binary.push_back(last % 2);
            num = Divide(num, 2);
        }
        
        string answer = "0";
        for(int i = 0; i < binary.size(); i++){
            answer = Multiple(answer, 2);
            answer = Add(answer, binary[i]);
        }
        cout << answer << endl;
    }
    return 0;
}
