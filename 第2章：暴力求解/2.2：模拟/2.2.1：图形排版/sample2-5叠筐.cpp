/*
例题2.5	叠筐	
http://acm.hdu.edu.cn/showproblem.php?pid=2074
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    char a, b;
    bool firstcase = true;
    char matrix[80][80];
    while(scanf("%d %c %c", &n, &a, &b) != EOF){
        if(firstcase){
            firstcase = false;
        }
        else{
            printf("\n");
        }
        for(int i = 0; i <= n / 2; i++){
            int j = n - 1 - i;  // (i,i)、(j,j)分别为当前圈的左上和右下坐标
            int len = n - 2 * i;  // 当前圈的边长
            char curchar;  // 当前圈的填充字符
            if((n / 2 - i) % 2 == 0){
                curchar = a;
            }
            else{
                curchar = b;
            }
            for(int k = 0; k < len; k++){
                matrix[i][i + k] = curchar;
                matrix[i + k][j] = curchar;
                matrix[j][j - k] = curchar;
                matrix[j - k][i] = curchar;
            }
        }
        matrix[0][0] = ' ';
        matrix[0][n - 1] = ' ';
        matrix[n - 1][0] = ' ';
        matrix[n - 1][n - 1] = ' ';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

