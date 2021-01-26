/*
例题10.5	复数集合（北京邮电大学复试上机题）	
http://t.cn/Ai98yYlt
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct Complex{
    int real;
    int imag;
    Complex(int r, int i):real(r), imag(i){}
    bool operator< (Complex c) const{
        if(real * real + imag * imag == c.real * c.real + c.imag * c.imag){
            return real < c.real;
        }
        else{
            return real * real + imag * imag < c.real * c.real + c.imag * c.imag;
        }
    }
};

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        priority_queue<Complex> PQ;
        while(n--){
            string str;
            cin >> str;
            if(str == "Pop"){
                if(PQ.empty()){
                    printf("empty\n");
                }
                else{
                    Complex c = PQ.top();
                    printf("%d+i%d\n", c.real, c.imag);
                    PQ.pop();
                    printf("SIZE = %d\n", PQ.size());
                }
            }
            else{
                int real, imag;
                scanf("%d+i%d", &real, &imag);
                PQ.push(Complex(real, imag));
                printf("SIZE = %d\n", PQ.size());
            }
            cin.ignore(1024, '\n');
        }
    }
    return 0;
}
