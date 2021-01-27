/*
习题10.5	开门人和关门人(浙江大学复试上机题)	
http://t.cn/AiCuM09f
*/


//  方法一：
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        cin.ignore(1024, '\n');
        map<string, string> inTimes, outTimes;
        string str;
        while(n--){
            getline(cin, str);
            int pos1 = str.find(' ');
            int pos2 = str.find(' ', pos1 + 1);
            string id, time1, time2;
            id = str.substr(0, pos1);
            time1 = str.substr(pos1 + 1, pos2 - pos1 - 1);
            //cout << "time1:" << time1 << endl;
            time2 = str.substr(pos2 + 1);
            //cout << "time2:" << time2 << endl;
            inTimes[time1] = id;
            outTimes[time2] = id;
        }
        map<string, string>::iterator it = inTimes.begin();
        cout << it->second << " ";
        it = (--outTimes.end());
        cout << it->second << endl;
    }
    return 0;
}


// 方法二：
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        cin.ignore(1024, '\n');
        map<string, string> inTime, outTime;
        while(n--){
            string id, in, out;
            cin >> id >> in >> out;
            inTime[in] = id;
            outTime[out] = id;
        }
        map<string, string>::iterator it = inTime.begin();
        cout << it->second << " ";
        it = --outTime.end();
        cout << it->second << endl;
    }
    return 0;
}
