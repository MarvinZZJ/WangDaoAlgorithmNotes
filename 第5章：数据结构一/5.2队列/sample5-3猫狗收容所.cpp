/*
例题5.3	猫狗收容所
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Animal {
    int number;
    int order;
    Animal(int n, int o): number(n), order(o){}
};

int main(){
    queue<Animal> cats, dogs;
    int n, order = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m, t;
        cin >> m >> t;
        //  有动物入收容所
        if(m == 1){
            if(t > 0){  // 收容狗
                dogs.push(Animal(t, order++));
            }
            else if(t < 0){  // 收容猫
                cats.push(Animal(t, order++));
            }
        }
        else{  // 有人要收养动物
            if(t == 0 && !cats.empty() && !dogs.empty()){
                if(dogs.front().order < cats.front().order){
                    cout << dogs.front().number << " ";
                    dogs.pop();
                }
                else{
                    cout << cats.front().number << " ";
                    cats.pop();
                }
            }
            else if(t == 0 && cats.empty() && !dogs.empty()){
                cout << dogs.front().number << " ";
                dogs.pop();
            }
            else if(t == 0 && !cats.empty() && dogs.empty()){
                cout << cats.front().number << " ";
                cats.pop();
            }
            else if(t == 1 && !dogs.empty()){
                cout << dogs.front().number << " ";
                dogs.pop();
            }
            else if(t == -1 && !cats.empty()){
                cout << cats.front().number << " ";
                cats.pop();
            }
        }
    }
    cout << endl;
    return 0;
}
