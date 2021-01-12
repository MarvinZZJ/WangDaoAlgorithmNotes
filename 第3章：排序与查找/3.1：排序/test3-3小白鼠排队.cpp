/*
习题3.3	小白鼠排队（北京大学复试上机题）	
http://t.cn/E9gXh9Z
*/

//  法一：
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Mouse{
    int weight;
    string color;
};

bool Compare(Mouse x1, Mouse x2){
    return x1.weight > x2.weight;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        Mouse arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].weight >> arr[i].color;
        }
        sort(arr, arr + n, Compare);
        for(int i = 0; i < n; i++){
            cout << arr[i].color << endl;
        }
    }
    return 0;
}

//  法二：
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Mouse{
    int weight;
    string color;
    bool operator< (Mouse m) const {
        return weight > m.weight;
    }
};

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        Mouse arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].weight >> arr[i].color;
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            cout << arr[i].color << endl;
        }
    }
    return 0;
}
