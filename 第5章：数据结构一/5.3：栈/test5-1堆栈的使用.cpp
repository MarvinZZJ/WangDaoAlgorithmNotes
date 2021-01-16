/*
习题5.1	堆栈的使用（吉林大学复试上机题）
http://t.cn/AiKKM6F6
*/

//  方法一：
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cctype>  // 调用isdigit()

using namespace std;


int GetNumber(string str, int index){
    int num = 0;
    while(index < str.size() && isdigit(str[index])){
        num = num * 10 + str[index++] - '0';
    }
    return num;
}

int main()
{
    int n;
    while(cin >> n){
        cin.ignore();  // 重要！用于将缓冲区存有的‘\n’获取掉，避免getline时直接获取了一个空串。
        if(n == 0){
             break;
        }
        stack<int> sta;
        while(n--){
            string str;
            getline(cin, str);
            if(str == "O" && !sta.empty()){
                sta.pop();
            }else if(str == "A" && !sta.empty()){
                cout << sta.top() << endl;
            }else if(str == "A" && sta.empty()){
                cout << "E" << endl;
            }else if(str[0] == 'P'){
                sta.push(GetNumber(str, 2));
            }
            str.clear();
        }
        cout << endl;
    }
    return 0;
}

//  方法二：
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)){
        cin.ignore(1024, '\n');
        if(n == 0){
            break;
        }
        stack<int> sta;
        for(int i = 0; i < n; i++){
            char c;
            scanf("%c", &c);
            if(c == 'A'){
                if(!sta.empty()){
                    printf("%d\n", sta.top());
                }
                else{
                    printf("E\n");
                }
            }
            else if(c == 'O' && !sta.empty()){
                sta.pop();
            }
            else if(c == 'P'){
                int num;
                scanf("%d", &num);
                sta.push(num);
            }
            cin.ignore(1024, '\n');
        }
        printf("\n");
    }
    return 0;
}

