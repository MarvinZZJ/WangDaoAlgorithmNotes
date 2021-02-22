/*
习题10.6	谁是你的潜在朋友（北京大学复试上机题）	
http://t.cn/AiCux4f7
*/

// 思路：
// 1：用map的<booknum, number>键值对表示booknum号的书一共有number个人喜欢
// 2：用一个数组person[i]表示第i人最喜欢的书的编号


#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 200 + 10;

int person[MAXN];

int main(){
    int n, m;
    while(cin >> n >> m){
        map<int, int> books;
        for(int i = 1; i <= n; i++){
            cin >> person[i];
            books[person[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(books[person[i]] == 1){
                cout << "BeiJu" << endl;
            }
            else{
                cout << books[person[i]] - 1 << endl;
            }
        }
    }
    return 0;
}
