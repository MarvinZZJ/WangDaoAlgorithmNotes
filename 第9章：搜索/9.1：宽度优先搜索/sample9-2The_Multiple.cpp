/*
例题9.2	Find The Multiple	
http://poj.org/problem?id=1426
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

long long BFS(int n){
    long long answer = 1;
    queue<long long> myQueue;
    myQueue.push(answer);
    while(!myQueue.empty()){
        answer = myQueue.front();
        myQueue.pop();
        if(answer >= n && answer % n == 0){
            return answer;
        }
        else{
            myQueue.push(answer * 10);
            myQueue.push(answer * 10 + 1);
        }
    }
    return -1;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        cout << BFS(n) << endl;
    }
    return 0;
}
