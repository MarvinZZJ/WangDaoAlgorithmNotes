/*
习题2.4	Repeater（北京大学复试上机题）
http://t.cn/E9jcaVb
*/

//  法一：
#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

char** fillOutput(char** temp, int n, int size, int q);

int main(){
    int n, q;
    while(cin >> n){
        if(n == 0)
            break;
        cin.ignore();
        char** temp = new char* [n];  //temp二维数组用于存储模板template
        for(int i = 0; i < n; i++){
            temp[i] = new char[n];
            cin.getline(temp[i], n + (int)1);
        }
        cin >> q;
        int size = (int)pow(n, q);

        char** output = fillOutput(temp, n, size, q);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout << output[i][j];
            }
            cout << endl;
        }
        for(int i = 0; i < size; i++){
            delete [] output[i];
        }
        delete[] output;
        for(int i = 0; i < n; i++){
            delete [] temp[i];
        }
        delete[] temp;
    }
    return 0;
}

char** fillOutput(char** temp, int n, int size, int q){
    if(q == 1)
        return temp;
    int lowSize = size / n;
    char** matrix = new char* [size];
    for(int i = 0; i < size; i++){
        matrix[i] = new char[size + 1];
        for(int j = 0; j < size; j++){
            matrix[i][j] = ' ';
        }
        matrix[i][size] = '\0';
    }

    char** subMatrix = fillOutput(temp, n, lowSize, q-1);
    for(int i = 0; i < n * lowSize; i += lowSize){
        for(int j = 0; j < n * lowSize; j += lowSize){
            if(temp[i / lowSize][j / lowSize] == ' ')
                continue;
            for(int m = 0; m < lowSize; m++){
                for(int k = 0; k < lowSize; k++){
                    matrix[i + m][j + k] = subMatrix[m][k];
                }
            }
        }
    }
    return matrix;
}


// 法二：
#include <iostream>
#include <cstdio>
#include <cmath>  // 用到pow()
#include <cstring>  // 用到memset()

using namespace std;

char pattern[5][5];
char matrix[3000][3000];

void Fill(int x, int y, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[x + i][y + j] = pattern[i][j];
        }
    }
}

void DFS(int x, int y, int n, int q){
    if(q == 1){
        Fill(x, y, n);
        return;
    }
    int len = pow(n, q - 1);  // 当前深度下的一个元素的长度
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(pattern[i][j] != ' '){
                DFS(x + i * len, y + j * len, n, q - 1);
            }
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        getchar();  // 取走缓冲区无用的回车键
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%c", &pattern[i][j]);
            }
            getchar();  // 取走缓冲区无用的回车键
        }
        memset(matrix, ' ', sizeof(matrix));
        int q;
        scanf("%d", &q);
        DFS(0, 0, n, q);
        int len = pow(n, q);  // 图案的长度
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
