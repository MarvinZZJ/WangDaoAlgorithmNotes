/*
习题8.2	全排列（北京大学复试上机题）	
http://t.cn/Ai0K0hXZ
*/

//方法一：递归方式1:
// len为待排长度

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

void Permutation(string str, int len){
    if(len == 1){
        cout << str << endl;
    }
    else{
        for(int i = str.size() - len; i < str.size(); i++){
            string temp(str);
            char select = temp[i];  //每次从后缀中选一个字母
            temp.erase(i, 1);  //删掉head并加入到前缀的最后
            temp.insert(str.size() - len, 1, select);
            Permutation(temp, len - 1);
        }
    }
}

int main(){
    string str;
    while(cin >> str){
        sort(str.begin(), str.end());
        Permutation(str, str.size());
        cout << endl;
    }
    return 0;
}



// 方法二：递归方式2：
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10;
char seq[MAXN];
bool visit[MAXN];

// len代表已排好序的字符长度
void GetPermutation(string str, int len){
    if(len == str.size()){
        for(int i = 0; i < str.size(); i++){
            cout << seq[i];
        }
        cout << endl;
    }
    else{
        // 选择一个未排序的字符
        for(int i = 0; i < str.size(); i++){
            if(visit[i]){
                continue;
            }
            else{
                visit[i] = true;
                seq[len] = str[i];
                GetPermutation(str, len + 1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    string str;
    memset(visit, false, sizeof(visit));
    while(cin >> str){
        sort(str.begin(), str.end());
        GetPermutation(str, 0);
        cout << endl;
    }
    return 0;
}




//方法三：非递归算法：

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool NextPermutation(string& str){
    int n = str.size();
    int index = n - 2;
    // 1.从右向左求拐点，使str[index] < str[index + 1]
    while(index >= 0 && str[index] > str[index + 1]){
        index--;
    }
    if(index < 0){ // 代表已经无下一个排列
        return false;
    }
    // 2.交换：将拐点右边从右往左找到第一个比str[index]大的数，进行交换
    for(int i = n - 1; i > index; i--){
        if(str[index] < str[i]){
            swap(str[index], str[i]);
            break;
        }
    }
    // 3.排序；(其实此时index后的字符串已经是递减排序，所以只需让其逆序即可）
    reverse(str.begin() + index + 1, str.end());
    return true;
}

int main(){
    string str;
    while(cin >> str){
        sort(str.begin(), str.end());
        do{
            cout << str << endl;
        }while(NextPermutation(str));
        cout << endl;
    }
}



// 方法四：
// 调用algorithm库中的系统函数next_pernutation

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        sort(str.begin(), str.end());
        do{
            cout << str << endl;
        }while(next_permutation(str.begin(), str.end()));
        cout << endl;
    }
}
