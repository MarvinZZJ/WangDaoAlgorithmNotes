/*
习题9.2	八皇后（北京大学复试上机题）	
http://t.cn/Ai0uOazs
*/

//  方法一：
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 10;

bool visitCol[MAXN];  // 用于记录第y列是否已有棋子

vector<int> answer;

bool IsValid(int row, int col, vector<pair<int, int>> sequence){
    for(int i = 0; i < sequence.size(); i++){
        if(abs(row - sequence[i].first) == abs(col - sequence[i].second)){
            return false;
        }
    }
    return true;
}

void DFS(int row, vector<pair<int, int>> sequence){
    if(sequence.size() == 8){
        int number = 0;
        for(int i = 0; i < 8; i++){
            number *= 10;
            number += sequence[i].second;
        }
        answer.push_back(number);
        return;
    }
    for(int col = 1; col <= 8; col++){
        if(visitCol[col] || !IsValid(row, col, sequence)){
            continue;
        }
        visitCol[col] = true;
        sequence.push_back(pair<int, int>(row, col));
        DFS(row + 1, sequence);
        sequence.pop_back();
        visitCol[col] = false;
    }
    return;
}

int main(){
    memset(visitCol, false, sizeof(visitCol));
    vector<pair<int, int>> sequence;
    DFS(1, sequence);
    int n;
    while(scanf("%d", &n) != EOF){
        cout << answer[n - 1] << endl;
    }
    return 0;
}



//  方法二：
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<string> queenStr;

bool FindKPlan(int k, int number, string str){
    // k为寻找第k个皇后串。number为准备放置第number个皇后。str为当前皇后串。
    if(number > 8){
        queenStr.push_back(str);
        if(++counter == k){
            return true;
        }
        return false;
    }
    else{
        for(int col = 1; col <= 8; col++){
            bool available = true;
            if(number != 1){
                for(int i = 0; i < str.size(); i++){
                    // 将放置第number个皇后的位置与已放置的皇后起冲突，则舍弃该位置
                    if((str[i] - '0') == col || abs(col - str[i] + '0') == abs(number - i - 1)){
                        available = false;
                        break;
                    }
                }
            }
            if(available){
                // 该位置可以放皇后
                char newQueen = (char)(col + '0');
                if(!FindKPlan(k, number + 1, str + newQueen)){
                    continue;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
}

int main()
{
    string str = "";
    FindKPlan(92, 1, str);

    int b;
    while(cin >> b){
        cout << queenStr[b - 1] << endl;
    }
    return 0;
}
