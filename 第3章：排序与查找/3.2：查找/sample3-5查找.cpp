/*
例题3.5	查找（北京邮电大学复试上机题）	
http://t.cn/E9g8aaR
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 110;
int arr[MAXN];

// 法一：线性查找
bool LinearSearch(int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target)
            return true;
    }
    return false;
}

// 法二：自定义二分查找
bool BinarySearch(int n, int target){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] < target){
            left = mid + 1;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            return true;
        }
    }
    return false;
}

//法四：系统自带的散列函数
unordered_map<int , bool> hashTable;

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            hashTable[arr[i]] = true;  // 法四
        }
        
        // 法一：
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int target;
            scanf("%d", &target);
            if(LinearSearch(n, target)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        

        
        // 法二：
        sort(arr, arr + n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int target;
            scanf("%d", &target);
            if(BinarySearch(n, target)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        

        
        // 法三：利用系统自带的二分查找
        // lower_bound:返回≥目标值得第一个位置的地址（不是下标！）
        // upper_bound:返回＞目标值的第一个位置的地址（不是下标！）
        sort(arr, arr + n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int target;
            scanf("%d", &target);
            int position = lower_bound(arr, arr + n, target) - arr;
            if(position != n && arr[position] == target){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        

        // 法四：
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int target;
            scanf("%d", &target);
            if(hashTable[target]){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
