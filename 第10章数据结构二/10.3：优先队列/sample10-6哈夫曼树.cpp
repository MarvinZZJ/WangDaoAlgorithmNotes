/*
例题10.6 哈夫曼树（北京邮电大学复试上机题）	
http://t.cn/AiCuGMki
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        priority_queue<int, vector<int>, greater<int>> PQ;
        while(n--){
            int x;
            cin >> x;
            PQ.push(x);
        }
        int answer = 0;
        while(PQ.size() > 1){
            int a = PQ.top();
            PQ.pop();
            int b = PQ.top();
            PQ.pop();
            answer += (a + b);
            PQ.push(a + b);
        }
        cout << answer << endl;
    }
    return 0;
}
