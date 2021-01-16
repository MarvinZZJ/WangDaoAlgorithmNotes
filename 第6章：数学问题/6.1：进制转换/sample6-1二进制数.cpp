/*
例题6.1	二进制数（北京邮电大学复试上机题）	
http://t.cn/AiCuKTOv
*/

//  方法一：
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void PrintBinary(unsigned int n){
    vector<int> binary;
    while(n != 0){
        binary.push_back(n % 2);
        n /= 2;
    }
    for(int i = binary.size() - 1; i >= 0; i--){
        cout << binary[i];
    }
    cout << endl;
}

int main(){
    unsigned int n;
    while(scanf("%d", &n) != EOF){
        PrintBinary(n);
    }
    return 0;
}



//  方法二：
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string Divide(string str, int x){
    int remainder = 0;
    for(int i = 0; i < str.size(); i++){
        int current = remainder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        remainder = current % x;
    }
    int pos = 0;
    while(str[pos] == '0'){
        pos++;
    }
    return str.substr(pos);
}

void ConvertToBinary(string num){
    vector<int> answer;
    while(num.size() != 0){
        int last = num[num.size() - 1] - '0';
        answer.push_back(last % 2);
        num = Divide(num, 2);
    }
    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i];
    }
    cout << endl;
}

int main()
{
    string num;
    while(cin >> num){
        ConvertToBinary(num);
    }
    return 0;
}
