/*
习题7.1	代理服务器（清华大学复试上机题）	
http://t.cn/E9emuS9
*/

//  方法一：
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 1000 + 10;

string proxy[MAXN];
string server[MAXN * 5];

int position[MAXN];  // position[i]表示第i小的代理服务器IP最多可从current开始遍历到第position[i]个IP之前的IP
                     // 当为m时，代表可以用该代理IP访问所要访问的所有IP地址

int Updata(int current, int n, int m){
    for(int i = current; i < m; i++){
        /*
        lower_bound()利用二分查找的方法在一个排好序的数组中进行查找。
        lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第
        一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过
        返回的地址减去起始地址begin,得到找到数字在数组中的下标。
        */
        int index = lower_bound(proxy, proxy + n, server[i]) - proxy;
        if(index == n || proxy[index] != server[i]){  // 代表server[i]与所有proxy不相同
            continue;
        }
        position[index] = min(position[index], i);
    }
    for(int i = 0; i < n; i++){
        current = max(current, position[i]);
    }
    return current;
}

int main(){
    int n, m;
    while(cin >> n){
        cin.ignore(1024, '\n');
        for(int i = 0; i < n; i++){
            cin >> proxy[i];
        }
        sort(proxy, proxy + n);
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> server[i];
        }
        int answer = -1;
        if(n == 1){
            int i;
            for(i = 0; i < m; i++){
                if(proxy[0] == server[i]){
                    break;
                }
            }
            if(i == m){
                answer++;
            }
        }
        else{
            int current = 0;  // 当前需要遍历的server开始的小标
            while(current != m){
                fill(position, position + n, m);
                current = Updata(current, n, m);
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}



//  方法二：
#include <iostream>
#include <string>

using namespace std;

// http://t.cn/E9emuS9

const int MAXN = 1001;
const int MAXM = 5001;

string proxy[MAXN];
string server[MAXM];

int main()
{
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> proxy[i];
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> server[i];
        }

        int index = 0, counter = 0, flag = 1;// index记录当前遍历服务器的序号
        while(index != m && flag){
            int maxNum = 0;
            for(int i = 0; i < n; i++){
                int currentIndex = index;
                while(proxy[i] != server[currentIndex] && currentIndex < m){
                    currentIndex++;
                }
                if(currentIndex - index > maxNum){
                    maxNum = currentIndex - index;
                }
            }
            if(maxNum == 0){  // 遍历失败
                flag = 0;
            }
            counter++;
            index += maxNum;
        }
        if(flag == 0){
            cout << "-1" << endl;
        }
        else{
            cout << counter - 1 << endl;
        }
    }
    return 0;
}
