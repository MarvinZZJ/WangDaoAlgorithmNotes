/*
习题9.1	玛雅人的密码	
http://t.cn/Ai0lUhJj
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

// 判断字符串是否有“2012”
bool FindCode(string str){
    if(str.find("2012", 0) != string::npos){
        return true;
    }
    else{
        return false;
    }
}

int BFS(string str){
    queue<string> Q;  // 存储状态的队列
    map<string, int> M;  // M[str]表示经历的交换次数，同时用于记录字符串是否已入队过
    Q.push(str);  // 初始状态的入队
    M[str] = 0;  // 初始状态交换次数为0
    while(!Q.empty()){
        string current = Q.front();
        Q.pop();
        if(FindCode(current)){
            return M[current];
        }
        // 状态转移
        for(int i = 0; i < current.size() - 1; i++){
            string nextStr = current;
            swap(nextStr[i], nextStr[i + 1]);  // 交换pos 与 pos+1 的值
            if(M.find(nextStr) == M.end()){  // 若字符未出现过
                Q.push(nextStr);
                M[nextStr] = M[current] + 1;
            }
            else{  // 曾出现过该字符，不处理
                continue;
            }
        }
    }
    return -1;  //未发现符合要求字符串
}

int main(){
    int n;
    string str;
    while(scanf("%d", &n) != EOF){
        cin >> str;
        cout << BFS(str) << endl;
    }
    return 0;
}
