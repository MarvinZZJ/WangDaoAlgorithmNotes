/*
习题2.5	Hello World for U（浙江大学复试上机题）	
http://t.cn/E9jizni
*/

//  法一：直接输出法
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void PrintU(string str, int row, int col){
    int len = str.size();
    for(int i = 0; i < row; i++){
        if(i < row - 1){
            cout << str[i];
            for(int j = 1; j <= col - 2; j++){
                cout << ' ';
            }
            cout << str[len - 1 - i] << endl;
        }
        else{
            for(int j = 0; j < col; j++){
                cout << str[row - 1 + j];
            }
            cout << endl;
        }
    }
}

int main(){
    string str;
    while(cin >> str){
        int len = str.size();
        int row, col;
        row = len / 3 + 1;
        col = len / 3 + len % 3;
        PrintU(str, row, col);
    }
    return 0;
}


//  法二：用缓存数组来保存字符阵列，再输出
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 80 + 10;
char matrix[MAXN][MAXN];

int main(){
    string str;
    while(cin >> str){
        int row = (str.size() + 2) / 3;
        int col = str.size() + 2 - row * 2;
        //  初始化matrix
        memset(matrix, ' ', sizeof(matrix));
        //  构造对应字符阵列
        int index = 0;
        for(int i = 0; i < row; i++){
            matrix[i][0] = str[index++];
        }
        for(int i = 1; i < col; i++){
            matrix[row - 1][i] = str[index++];
        }
        for(int i = row - 2; i >= 0; i--){
            matrix[i][col - 1] = str[index++];
        }
        //  输出
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
