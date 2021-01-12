/*
习题3.7	找位置（华中科技大学复试上机题）	
http://t.cn/E9eh4jY
*/

//  法一：不使用vector和map
#include <iostream>
#include <cstdio>

using namespace std;

// http://t.cn/E9eh4jY

const int MAXN = 101;
int main()
{
    string str;
    while(cin >> str){
        int flag[MAXN]={0};  // 用于记录对应下标的元素是否已经输出
        int len =str.length();

        int counter[123] = {0};  // 记录字符出现的次数
        for(int i = 0; i < len; i++){
            counter[(int)str[i]]++;
        }

        for(int i = 0; i < len; i++){
            if(flag[i] == 0 && counter[(int)str[i]] > 1){
                cout << str[i] << ":" << i;
                flag[i] = 1;
                for(int j = i + 1; j < len; j++){
                    if(str[i] == str[j]){
                        cout << "," << str[j] << ":" << j;
                        flag[j] = 1;
                    }
                }
                printf("\n");
            }
        }
        str.clear();
    }
    return 0;
}


//  方法二：使用vector<char>记录字符首次出现的次序；使用map<char, vector<int>>记录每个字符出现的所有下标位置
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 100 + 10;

map<char, vector<int>> myMap;

vector<char> charOrder;

int main(){
    string str;
    while(cin >> str){
        for(int i = 0; i < str.size(); i++){
            if(myMap.count(str[i]) == 0){
                myMap[str[i]] = vector<int>(1, i);
                charOrder.push_back(str[i]);
            }
            else{
                myMap[str[i]].push_back(i);
            }
        }
        for(int i = 0; i < charOrder.size(); i++){
            if(myMap[charOrder[i]].size() == 1){
                continue;
            }
            for(int j = 0; j < myMap[charOrder[i]].size(); j++){
                if(j == myMap[charOrder[i]].size() - 1){
                    printf("%c:%d\n", charOrder[i], myMap[charOrder[i]][j]);
                }
                else{
                    printf("%c:%d,", charOrder[i], myMap[charOrder[i]][j]);
                }
            }
        }
        charOrder.clear();
        myMap.clear();
    }
    return 0;
}
