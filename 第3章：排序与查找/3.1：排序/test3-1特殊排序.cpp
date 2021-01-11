/*
习题3.1	特殊排序（华中科技大学复试上机题）	
http://t.cn/E9gio39
*/

//  法一：用数组
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr, arr + n);

        if(n == 1){
            cout << arr[0] <<endl;
            cout << -1 << endl;
            continue;
        }
        cout << arr[n - 1] << endl;
        for(int i = 0; i < n - 1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


//  法二：用vector
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int n;
    int x;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        cout << arr[arr.size() - 1] << endl;
        arr.pop_back();
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        if(arr.empty()){
            cout << -1;
        }
        cout << endl;
        arr.clear();
    }
    return 0;
}
