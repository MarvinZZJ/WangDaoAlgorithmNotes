/*
习题11.3	Head of a Gang（浙江大学复试上机题）	
http://t.cn/AiOzQMBH
*/


//  解法一：（推荐）
//  利用map<string, string> father存储每个人的老大是谁，初始时每个人的老大都是自己
//  利用map<string, int> weight;来存储每个人的权重总和，在Union时用于判断谁作为根

#include <iostream>
#include <cstdio>
#include <map>
#include <string>


using namespace std;

const int MAXN = 1000 + 10;

struct Calls{
    string name1;
    string name2;
    int time;
};

Calls calls[MAXN];

map<string, string> father;
map<string, int> weight;

string FindRoot(string x){
    if(x != father[x]){
        father[x] = FindRoot(father[x]);
    }
    return father[x];
}

void Union(string x, string y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){
        if(weight[x] > weight[y]){
            father[y] = x;
        }
        else{
            father[x] = y;
        }
    }
    return;
}

int main(){
    int n, k;
    while(cin >> n >> k){
        father.clear();
        weight.clear();
        for(int i = 0; i < n; i++){
            cin >> calls[i].name1 >> calls[i].name2 >> calls[i].time;
            father[calls[i].name1] = calls[i].name1;
            father[calls[i].name2] = calls[i].name2;
            weight[calls[i].name1] += calls[i].time;
            weight[calls[i].name2] += calls[i].time;
        }
        for(int i = 0; i < n; i++){
            Union(calls[i].name1, calls[i].name2);
        }
        map<string, int> sumWeight;
        map<string, int> number;
        map<string, int> gangs;
        for(map<string, string>::iterator it = father.begin(); it != father.end(); it++){
            string root = FindRoot(it->first);
            sumWeight[root] += weight[it->first];
            number[root]++;
        }
        for(map<string, int>::iterator it = sumWeight.begin(); it != sumWeight.end(); it++){
            if(it->second > 2 * k && number[it->first] > 2){
                gangs[it->first] = number[it->first];
            }
        }
        cout << gangs.size() << endl;
        for(map<string, int>::iterator it = gangs.begin(); it != gangs.end(); it++){
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}




//  解法二：
#include <iostream>
#include <map>

using namespace std;

// http://t.cn/AiOzQMBH

struct pInfo{
    string headName;  // 存储的是所属集合的根的人名
    int weight;
    int height;  // 用于合并时可以实现：矮树作为高树的子树
    pInfo():headName(""), weight(0), height(0){}
    pInfo(string hn, int w, int h): headName(hn), weight(w), height(h){}
};

struct gInfo{
    string realHeadName;  // 最后存放的为真正的头目
    int num;
    int sumWeight;
    gInfo(): realHeadName(""), num(0), sumWeight(0){}
    gInfo(string rhn, int n, int sw): realHeadName(rhn), num(n), sumWeight(sw){}
};

map<string, pInfo> people;  // 用来存放每个人的临时头目名及其通话时长（自身权重）
map<string, gInfo> gangs;  // 每个帮派以其中一个人作为标记（即作为key），而value中将记录真正的帮派头目名、帮派人数、总的通话时长（帮派总权重），并且可以按序输出
map<string, int> outputGangs;  // 以realHeadName作为key的帮派输出图,value 为帮派人数

string FindRoot(string x){
    if(people[x].headName != x){
        people[x].headName = FindRoot(people[x].headName);  // 压缩路径
    }
    return people[x].headName;
}

void Union(string x, string y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){
        if(people[x].height > people[y].height){
            people[y].headName = x;
        }
        else if(people[x].height < people[y].height){
            people[x].headName = y;
        }
        else{
            people[y].headName = x;
            people[x].height++;
        }
    }
    return ;
}

void GetoutputGang(int k){
    map<string, pInfo>::iterator iter = people.begin();
    for(; iter != people.end(); iter++){
        string headName = FindRoot(iter->first);
        if(gangs.find(headName) == gangs.end()){  // 该人还没有帮派，则自己组建一个帮派
            gInfo sample(headName, 1, iter->second.weight / 2);
            gangs.insert(pair<string, gInfo>(headName, sample));
        }
        else{
            gangs[headName].num++;
            gangs[headName].sumWeight += iter->second.weight / 2;
            if(iter->second.weight > people[gangs[headName].realHeadName].weight){  //该人的权重大于所在帮派当前帮派真实老大的权重，则替换真实老大
                gangs[headName].realHeadName = iter->first;
            }
        }
    }
    // 将帮派的key修改为各个帮派的realHeadName
    map<string, gInfo>::iterator it = gangs.begin();
    for(; it != gangs.end(); it++){
        if(it->second.num > 2 && it->second.sumWeight > k){  // 该帮派权重大于k，并且人数大于2。满足输出帮派的要求
            // cout << "帮派：" << it->second.realHeadName << " 的总权值为：" << it->second.sumWeight << endl;
            outputGangs[it->second.realHeadName] = it->second.num;
        }
    }
    return ;
}

int main()
{
    int n, k;
    while(cin >> n >> k){
        cin.ignore(1024, '\n');  // 删除换行符
        // 初始化
        people.clear();
        gangs.clear();
        outputGangs.clear();
        while(n--){
            string x, y;
            int weight;
            cin >> x >> y >>weight;
            if(people.find(x) == people.end()){
                people[x] = pInfo(x, weight, 0);
            }
            else{
                people[x].weight += weight;
            }
            if(people.find(y) == people.end()){
                people[y] = pInfo(y, weight, 0);
            }
            else{
                people[y].weight += weight;
            }
            Union(x, y);
        }
        GetoutputGang(k);
        cout << outputGangs.size() << endl;
        map<string, int>::iterator iter = outputGangs.begin();
        for(; iter != outputGangs.end(); iter++){
            cout << iter->first << " " << iter->second << endl;
        }
    }
    return 0;
}
