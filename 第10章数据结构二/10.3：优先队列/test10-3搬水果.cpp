/*
习题10.3	搬水果（吉林大学复试上机题）	
http://t.cn/AiCu5nsQ
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> PQ;
        while(n--){
            unsigned int x;
            cin >> x;
            PQ.push(x);
        }
        unsigned int answer = 0;
        while(PQ.size() > 1){
            unsigned int a = PQ.top();
            PQ.pop();
            unsigned int b = PQ.top();
            PQ.pop();
            answer += (a + b);
            PQ.push(a + b);
        }
        cout << answer << endl;
    }
    return 0;
}
