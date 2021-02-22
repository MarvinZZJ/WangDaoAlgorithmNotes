/*
习题10.4	统计同成绩学生人数（浙江大学复试上机题）	
http://t.cn/AiCuM7nj
*/

// 方法一：利用map
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        map<int, int> score;
        while(n--){
            int x;
            cin >> x;
            score[x]++;
        }
        int question;
        cin >> question;
        cout << score[question] << endl;
    }
    return 0;
}



// 法一：利用数组
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int counter[101];  // 记录对应成绩的人数

int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        memset(counter, 0, sizeof(counter));  // 初始化各分值人数
        while(n--){
            int score;
            cin >> score;
            counter[score]++;
        }

        int question;
        cin >> question;
        cout << counter[question] << endl;
    }
    return 0;
}
