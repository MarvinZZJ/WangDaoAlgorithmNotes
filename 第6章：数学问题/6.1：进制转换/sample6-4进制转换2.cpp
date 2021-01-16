/*
例题6.4	进制转换2（清华大学复试上机题）	
http://t.cn/AiCuKG7E
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int CharToInt(char c){
    if(isdigit(c)){
        return c - '0';
    }
    else{
        return c - 'A' + 10;
    }
}

char IntToChar(int x){
    if(x < 10){
        return x + '0';
    }
    else{
        return x - 10 + 'A';
    }
}

int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF){
        cin.ignore(1024, '\n');
        string str;
        cin >> str;
        long long num = 0;
        for(int i = 0; i < str.size(); i++){
            num *= m;
            num += CharToInt(str[i]);
        }

        vector<char> answer;
        while(num != 0){
            answer.push_back(IntToChar(num % n));
            num /= n;
        }

        for(int i = answer.size() - 1; i >= 0; i--){
            cout << answer[i];
        }
        cout << endl;
    }
    return 0;
}
