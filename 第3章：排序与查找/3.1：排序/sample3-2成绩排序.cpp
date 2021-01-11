/*
例题3.2	成绩排序（清华大学复试上机题）	
http://t.cn/E9d3ysv
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//  法一：重载operator<
struct Student {
    int id;
    int score;
    bool operator< (Student stu) const{
        if(score == stu.score){
            return id < stu.id;
        }
        else{
            return score < stu.score;
        }
    }
};

const int MAXN = 100 + 10;

Student students[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            cin >> students[i].id >> students[i].score;
        }
        sort(students, students + n);
        for(int i = 0; i < n; i++){
            cout << students[i].id << " " << students[i].score << endl;
        }
    }
}

//  法二：利用比较函数
struct Student {
    int id;
    int score;
};

const int MAXN = 100 + 10;

Student students[MAXN];

bool Compare(Student s1, Student s2){
    if(score == stu.score){
        return id < stu.id;
    }
    else{
        return score < stu.score;
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            cin >> students[i].id >> students[i].score;
        }
        sort(students, students + n, Compare);
        for(int i = 0; i < n; i++){
            cout << students[i].id << " " << students[i].score << endl;
        }
    }
}
