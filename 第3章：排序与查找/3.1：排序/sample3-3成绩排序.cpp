/*
例题3.3	成绩排序2（清华大学复试上机题）	
http://t.cn/E9gyHM1
*/

//  法一：
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int score;
    int order;
};

bool CompareDescending(Student s1, Student s2){
    if(s1.score == s2.score){
        return s1.order < s2.order;
    }
    else{
        return s1.score > s2.score;
    }
}

bool CompareAscending(Student s1, Student s2){
    if(s1.score == s2.score){
        return s1.order < s2.order;
    }
    else{
        return s1.score < s2.score;
    }
}

int main(){
    int n;
    int type;
    while(scanf("%d%d", &n, &type) != EOF){
        Student arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].name >> arr[i].score;
            arr[i].order = i;
        }
        if(type == 0){
            sort(arr, arr + n, CompareDescending);
        }
        else{
            sort(arr, arr + n, CompareAscending);
        }
        for(int i = 0; i < n; i++){
            cout << arr[i].name << " " << arr[i].score << endl;
        }
    }
    return 0;
}

// 法二：利用vector
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    int type;
    vector<vector<string>> scores(101);
    string name = "";
    int score;
    while(scanf("%d%d", &n, &type) != EOF){
        for(int i = 0; i < n; i++){
            cin >> name >> score;
            scores[score].push_back(name);
        }
        if(type == 0){  // 降序排序
            for(int i = 100; i >= 0; i--){
                if(scores[i].size()){
                    for(int j = 0; j < scores[i].size(); j++){
                        cout << scores[i][j] << " " << i <<endl;
                    }
                }
            }
        }
        else{  // 升序排序
            for(int i = 0; i <= 100; i++){
                if(scores[i].size()){
                    for(int j = 0; j < scores[i].size(); j++){
                        cout << scores[i][j] << " " << i <<endl;
                    }
                }
            }
        }
        // 清除此次录入的人
        for(int i = 0; i <= 100; i++){
            if(!scores[i].empty()){
                scores[i].clear();
            }
        }
    }
}
