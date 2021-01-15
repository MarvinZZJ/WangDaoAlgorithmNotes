/*
习题4.1	skew数（北京大学复试上机题）	
http://t.cn/Ai8IALKI
*/

//  方法一：利用函数pow()
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    string str;
    int sum;
    while(cin >> str){
        sum = 0;
        for(int i = 0; i < str.size(); i++){
            sum += (int)(str[i] - '0') * (pow(2, str.size() - i) - 1);
        }
        cout << sum << endl;
    }
    return 0;
}


//  方法二：利用算数左移<<
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        int sum = 0;
        for(int i = 0; i < str.size(); i++){
            sum += (str[i] - '0') * ((1 << (str.size() - i)) - 1);
        }
        cout << sum << endl;
    }
    return 0;
}
