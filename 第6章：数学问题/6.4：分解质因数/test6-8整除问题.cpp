/*
习题6.8	整除问题（上海交通大学复试上机题）	
http://t.cn/Aip7eHBD
*/

//  方法一：使用数组来存储n和a的质因数分解形式
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// http://t.cn/Aip7eHBD

const int MAXN = 1000 + 1;

bool isPrime[MAXN];

vector<int> prime;

void Initial(){
    for(int i = 0; i < MAXN; i++){
        if(i == 0 || i == 1){
            isPrime[i] = false;
        }
        else{
            isPrime[i] = true;
        }
    }

    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = i * i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void TurnPrimeFunc(int num, int (&func)[MAXN]){
    for(int i = 0; i < prime.size(); i++){
        if(num < prime[i]){
            break;
        }
        while(num % prime[i] == 0){
            func[prime[i]]++;
            num /= prime[i];
        }
    }
}

int main()
{
    Initial();
    int n, a;
    while(cin >> n >> a){
        int sizeOfPrime = prime.size();
        //求n!的素数表达式，即：分别求2~n的素数表达式，然后将这些表达式相乘。
        int nFunc[MAXN];  // 下标代表对应的底数，每个元素值代表对应下标底数的指数值。
        for(int i = 0; i < MAXN; i++){
            nFunc[i] = 0;
        }
        for(int i = 2; i <= n; i++){
            TurnPrimeFunc(i, nFunc);
        }

        //求a的素数表达式。
        int aFunc[MAXN];  // 下标代表对应的底数，每个元素值代表对应下标底数的指数值。
        for(int i = 0; i < MAXN; i++){
            aFunc[i] = 0;
        }
        TurnPrimeFunc(a, aFunc);

        // nFunc与aFunc底数对应的指数分别相除，取最小的所得值即为k。
        int minK = MAXN;
        for(int i = 0; i < sizeOfPrime; i++){
            if(aFunc[prime[i]] != 0 && nFunc[prime[i]] / aFunc[prime[i]] < minK){
                minK = nFunc[prime[i]] / aFunc[prime[i]];
            }
        }
        cout << minK << endl;
    }
    return 0;
}


//  方法二：使用map来存储n和a的质因数分解形式
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

const int INF = INT_MAX;

const int MAXN = 1e3 + 1;

bool isPrime[MAXN];

vector<int> prime;

void Initial(){
    for(int i = 0; i < MAXN; i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = i * i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
    return;
}

int main(){
    Initial();
    int n, a;
    while(scanf("%d%d", &n, &a) != EOF){
        map<int, int> exponentN;  //存储n!的质因数分解
        for(int i = 2; i <= n; i++){
            int number = i;
            for(int j = 0; j < prime.size() && prime[j] <= number; j++){
                while(number % prime[j] == 0){
                    exponentN[prime[j]]++;
                    number /= prime[j];
                }
            }
        }
        map<int, int> exponentA;  //存储a的质因数分解
        for(int i = 0; i < prime.size() && prime[i] <= a; i++){
            while(a % prime[i] == 0){
                exponentA[prime[i]]++;
                a /= prime[i];
            }
        }
        int answer = INF;
        for(map<int, int>::iterator it = exponentA.begin(); it != exponentA.end(); it++){
            if(exponentN.find(it->first) == exponentN.end()){
                answer = 0;
                break;
            }
            else{
                answer = min(answer, exponentN[it->first] / it->second);
            }
        }
        printf("%d", answer);
    }
    return 0;
}
