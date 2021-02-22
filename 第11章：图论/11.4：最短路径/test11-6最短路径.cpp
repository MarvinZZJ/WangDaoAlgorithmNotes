/*
习题11.6	最短路径（上海交通大学复试上机题）	
http://t.cn/AilPCAuL
*/

// 方法一（不推荐）：利用结构体BigInteger存储路径长度
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


struct BigInteger{
    int length;
    int digit[10000];
    friend ostream& operator<<(ostream& out, const BigInteger& b);
    BigInteger();
    BigInteger(int x);
    BigInteger(const BigInteger& b);
    bool operator<(const BigInteger& b);
    bool operator<=(const BigInteger& b);
    bool operator==(const BigInteger& b);
    BigInteger operator=(int x);
    BigInteger operator=(const BigInteger& b);
    BigInteger operator+(const BigInteger& b);
    BigInteger operator-(const BigInteger& b);
    BigInteger operator*(const BigInteger& b);
    BigInteger operator%(const BigInteger& b);
};

ostream& operator<<(ostream& out, const BigInteger& b){
    for(int i = b.length - 1; i >= 0; i--){
        out << b.digit[i];
    }
    return out;
}

BigInteger::BigInteger(){
    length = 0;
    memset(digit, 0, sizeof(digit));
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length++] = x;
    }
    while(x != 0){
        digit[length++] = x % 10;
        x /= 10;
    }
}

BigInteger::BigInteger(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < b.length; i++){
        digit[i] = b.digit[i];
    }
}

bool BigInteger::operator<(const BigInteger& b){
    if(length < b.length){
        return true;
    }
    else if(length > b.length){
        return false;
    }
    else{
        for(int i = length - 1; i >= 0; i--){
            if(digit[i] != b.digit[i]){
                return digit[i] < b.digit[i];
            }
        }
        return false;
    }
}

bool BigInteger::operator<=(const BigInteger& b){
    if(length < b.length){
        return true;
    }
    else if(length > b.length){
        return false;
    }
    else{
        for(int i = length - 1; i >= 0; i--){
            if(digit[i] != b.digit[i]){
                return digit[i] < b.digit[i];
            }
        }
        return true;
    }
}

bool BigInteger::operator==(const BigInteger& b){
    if(length != b.length){
        return false;
    }
    for(int i = length - 1; i >= 0; i--){
        if(digit[i] != b.digit[i]){
            return false;
        }
    }
    return true;
}

BigInteger BigInteger::operator=(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length++] = x;
    }
    else{
        while(x != 0){
            digit[length++] = x % 10;
            x /= 10;
        }
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < length; i++){
        digit[i] = b.digit[i];
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger& b){
    BigInteger answer;
    int carry = 0;
    for(int i = 0; i < length || i < b.length; i++){
        int current = carry + digit[i] + b.digit[i];
        carry = current / 10;
        answer.digit[answer.length++] = current % 10;
    }
    if(carry != 0){
        answer.digit[answer.length++] = carry;
    }
    return answer;
}

BigInteger BigInteger::operator-(const BigInteger& b){
    BigInteger answer;
    int carry = 0;
    for(int i = 0; i < length; i++){
        int current = digit[i] - b.digit[i] - carry;
        if(current < 0){
            carry = 1;
            current += 10;
        }
        else{
            carry = 0;
        }
        answer.digit[answer.length++] = current;
    }
    while(answer.digit[answer.length - 1] == 0 && answer.length > 1){
        answer.length--;
    }
    return answer;
}

BigInteger BigInteger::operator*(const BigInteger& b){
    BigInteger answer;
    answer.length = length + b.length;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < b.length; j++){
            answer.digit[i + j] = digit[i] * b.digit[j];
        }
    }
    for(int i = 0; i < answer.length; i++){
        answer.digit[i + 1] += answer.digit[i] / 10;
        answer.digit[i] %= 10;
    }
    while(answer.digit[answer.length - 1] == 0 && answer.length > 1){
        answer.length--;
    }
    return answer;
}

BigInteger BigInteger::operator%(const BigInteger& b){
    BigInteger remainder = 0;
    BigInteger temp = b;
    for(int i = length - 1; i >= 0; i--){
        if(!(remainder.length == 1 && remainder.digit[0] == 0)){
            for(int j = remainder.length - 1; j >= 0; j--){
                remainder.digit[j + 1] = remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while(temp <= remainder){
            remainder = remainder - temp;
        }
    }
    return remainder;
}

const int MAXN = 100 + 10;

const int MOD = 1e5;

struct Edge{
    int to;
    BigInteger length;
    Edge(int t, BigInteger l): to(t), length(l){}
};

vector<Edge> graph[MAXN];

BigInteger minDistance[MAXN];

struct Point{
    int number;
    BigInteger distance;
    Point(int n, BigInteger d): number(n), distance(d){}
    bool operator< (Point p) const {
        return p.distance < distance;
    }
};

void Dijkstra(int start){
    minDistance[start] = 0;
    priority_queue<Point> PQ;
    PQ.push(Point(start, minDistance[start]));
    while(!PQ.empty()){
        int u = PQ.top().number;
        PQ.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            BigInteger l = graph[u][i].length;
            if(minDistance[u] + l < minDistance[v]){
                minDistance[v] = minDistance[u] + l;
                PQ.push(Point(v, minDistance[v]));
            }
        }
    }
    return;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        memset(graph, 0, sizeof(graph));
        BigInteger length = 1;
        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
            length = length * BigInteger(2);
        }
        BigInteger INF = length;
        fill(minDistance, minDistance + n, INF);
        Dijkstra(0);
        for(int i = 1; i < n; i++){
            if(minDistance[i] == INF){
                cout << "-1" << endl;
            }
            else{
                cout << minDistance[i] % MOD << endl;
            }
        }
    }
    return 0;
}



#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// http://t.cn/AilPKHTx

// 思路： 因为题目中边的长度为2^k，因此可以利用字符串来存放对应的用
//        二进制数表示的边长值。其中由于需要进行边长的比较（在Dijkstra算法
//        的判断是否松弛操作中会用到），因此二进制数在字符串中的表示
//        要以“低位数值保存在高位地址下标”的原则进行。且每个字符串的长度要等于501，因为m小于等于500


const int MAXN = 100;  // 城市点标号0~99

struct Edge{
    int to;  // 终点
    string length;  // 长度（二进制数）
    Edge(int t, string l): to(t), length(l){}
};

struct Point{
    int number;  // 点的标号
    string distance;  // 距离（二进制数）
    Point(int n, string d): number(n), distance(d){}
    bool operator< (const Point& p) const{
        return distance > p.distance;
    }
};

string dist[MAXN];  // 源点到各点的距离（二进制数）

vector<Edge> graph[MAXN];  // 邻接表

// 初始化dist数组
void Initial(){
    for(int i = 0; i < MAXN; i++){
        dist[i] = string(501, '1');
    }
    dist[0] = string(501, '0');  // 该题源点为0
}


// 获取2^i次方的二进制字符串。（低位储存于高位地址，方便字符串比较大小）
string GetLength(int i){
    string s(501, '0');
    s[s.size() - 1 - i] = '1';
    return s;
}


// 两个不相等的二进制数相加（由题意可知两个相加的数一定不是相等的）
string Add(string a, string b){
    string s;
    for(int i = 0; i < a.size(); i++){
        s.append(1, (a[i] + b[i] - '0'));
    }
    return s;
}


// 求到编号0的单源最短路径
void Dijkstra(){
    priority_queue<Point> minDis;  // 用于筛选最短距离的点
    minDis.push(Point(0, dist[0]));
    while(!minDis.empty()){
        int u = minDis.top().number;  // 获取当前离源点最近的点的编号
        minDis.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            string len = graph[u][i].length;
            string tempLen = Add(dist[u], len);
            if(dist[v] > tempLen){
                dist[v] = tempLen;
                minDis.push(Point(v, dist[v]));
            }
        }
    }
    return ;
}


// 快速幂取模
int FastExponentiation(string s){
    int answer = 0;
    int a = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '1'){
            answer += a;
            answer %= 100000;
        }
        a *= 2;
        a %= 100000;
    }
    return answer;
}


int main()
{
    int n, m;
    while(cin >> n >> m){
        Initial();  // 初始化dist数组
        for(int i = 0; i < m; i++){  // 长度与i有关
            int x, y;
            cin >> x >> y;
            string len = GetLength(i);
            graph[x].push_back(Edge(y, len));
            graph[y].push_back(Edge(x, len));
        }
        Dijkstra();
        string inf(501, '1');  // inf代表无穷
        for(int i = 1; i < n; i++){
            if(dist[i] == inf){
                cout << "-1" << endl;
            }
            else{
                cout << FastExponentiation(dist[i]) << endl;
            }
        }
    }
    return 0;
}
