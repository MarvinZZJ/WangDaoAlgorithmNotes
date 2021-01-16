/*
习题6.3	进制转换（北京大学复试上机题）	
http://t.cn/AiCuig9B
*/


//  方法一：当输出的十进制数很大时，只能用字符串表示十进制数
#include <iostream>
#include <vector>

using namespace std;

// http://t.cn/AiCuig9B

string CharToIntstring(char c){
    string str;
    if(c == 'A'){
        str = "10";
    }
    else if(c == 'B'){
        str = "11";
    }
    else if(c == 'C'){
        str = "12";
    }
    else if(c == 'D'){
        str = "13";
    }
    else if(c == 'E'){
        str = "14";
    }
    else if(c == 'F'){
        str = "15";
    }
    else{
        str = c;
    }
    return str;
}

string Multiple(string str, int x, int bit){
    int carry = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        int current = carry + (str[i] - '0') * x;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry != 0){
        str = (char)(carry + '0') + str;
    }
    if(bit != 0 && str != "0"){
        str.append(bit, '0');
    }
    //cout << "第" << bit + 1 << "位乘数乘被乘数的结果为：" << str << endl;
    return str;
}

string Add(string x, string y){
    string answer = "";
    int carry = 0;
    int i = x.size() - 1, j = y.size() - 1;
    for(; i >= 0 && j >= 0; i--, j--){
        int current = (x[i] - '0') + (y[j] - '0') + carry;
        answer = (char)(current % 10 + '0') + answer;
        carry = current / 10;
    }
    while(i >= 0){
        int current = x[i] - '0' + carry;
        answer = (char)(current % 10 + '0') + answer;
        carry = current / 10;
        i--;
    }
    while(j >= 0){
        int current = y[j] - '0' + carry;
        answer = (char)(current % 10 + '0') + answer;
        carry = current / 10;
        j--;
    }
    if(carry != 0){
        answer = "1" + answer;
    }
    return answer;
}


int main()
{
    string str;
    while(cin >> str){
        str = str.substr(2);
        string answer = "0";
        for(int i = 0; i < str.size(); i++){
            //cout << "Round:" << i << endl;
            // 乘法运算
            string temp1 = Multiple(answer, 6, 0);
            string temp2 = Multiple(answer, 1, 1);
            answer = Add(temp1, temp2);
            //cout << "Multiple result:" << answer << endl;
            // 加法运算
            string aNum = CharToIntstring(str[i]);
            answer = Add(answer, aNum);
            //cout << "Add result:" << answer << endl << endl;
        }
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i];
        }
        cout << endl;
    }
    return 0;
}


//  方法二：当输出的十进制数用int整形变量或long long型变量能表示时
#include <iostream>
#include <cstdio>
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

void ConvertAndPrint(string num, int x){
    int answer = 0;
    for(int i = 0; i < num.size(); i++){
        answer = answer * x + CharToInt(num[i]);
    }
    cout << answer << endl;
    return;
}

int main(){
    string str;
    while(cin >> str){
        str = str.substr(2);
        ConvertAndPrint(str, 16);
    }
    return 0;
}
