/*
习题10.2	查找第K小的数（北京邮电大学复试上机题）	
http://t.cn/AiCu5hcK
*/

// 方法一：利用小根堆
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        priority_queue<int, vector<int>, greater<int>> PQ;
        while(n--){
            int x;
            cin >> x;
            PQ.push(x);
        }
        int current = PQ.top();
        PQ.pop();
        int k;
        cin >> k;
        for(int i = 2; i <= k; i++){
            while(current == PQ.top()){
                PQ.pop();
            }
            current = PQ.top();
            PQ.pop();
        }
        cout << current << endl;
    }
    return 0;
}


// 方法二：利用快速排序
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main()
{
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int k;
        cin >> k;
        int counter = 2; // 正在寻找第counter小的数
        int pro = arr[0]; // 保存第counter-1小的元素值
        for(int i = 1; i < n && counter <= k; i++){
            if(pro == arr[i]){  // 与上一个元素相同时，跳过
                continue;
            }
            else{  // 找到下一个不同的元素时，保存其值，并开始寻找第counter+1小元素
                pro = arr[i];
                counter++;
            }
        }
        cout << pro << endl;
    }
    return 0;
}
