/*
习题11.1	找出直系亲属（浙江大学复试上机题）	
http://t.cn/AiOzTX5c
*/


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 30;

int child[MAXN];

void Initial(){
    for(int i = 0; i < MAXN; i++){
        child[i] = i;
    }
    return;
}

int Generation(int x, int y){
    int a = x;
    int level = 0;
    while(a != child[a]){
        level++;
        a = child[a];
        if(a == y){
            return level;
        }
    }
    int b = y;
    level = 0;
    while(b != child[b]){
        level--;
        b = child[b];
        if(b == x){
            return level;
        }
    }
    return 0;
}

string Relationship(int level){
    string answer = "";
    if(level == 0){
        answer += "-";
    }
    else if(level == 1){
        answer += "parent";
    }
    else if(level == 2){
        answer += "grandparent";
    }
    else if(level > 2){
        while(level > 2){
            answer += "great-";
            level--;
        }
        answer += "grandparent";
    }
    else if(level == -1){
        answer += "child";
    }
    else if(level == -2){
        answer += "grandchild";
    }
    else if(level < -2){
        while(level < -2){
            answer += "great-";
            level++;
        }
        answer += "grandchild";
    }
    return answer;
}

int main(){
    int n, m;
    //while(scanf("%d%d", &n, &m) != EOF){
    while(cin >> n >> m){
        cin.ignore(1024, '\n');
        Initial();
        for(int i = 0; i < n; i++){
            string str;
            //cin >> str;
            //cin.ignore(1024, '\n');
            getline(cin, str);
            if(str[1] != '-'){
                child[str[1] - 'A'] = str[0] - 'A';
            }
            if(str[2] != '-'){
                child[str[2] - 'A'] = str[0] - 'A';
            }
        }
        for(int i = 0; i < m; i++){
            string str;
            //cin >> str;
            //cin.ignore(1024, '\n');
            getline(cin, str);
            int level = Generation(str[0] - 'A', str[1] - 'A');
            cout << Relationship(level) << endl;
        }
    }
    return 0;
}
