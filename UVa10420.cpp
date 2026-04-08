/*
    map<key型別, value型別> 名字;
    string -> key
    int -> value
    count -> map名字
*/


#include <iostream>
#include <map>
#include <sstream>  // stringstream
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();  // 清掉換行

    map<string, int> count;   

    while(n--){
        string line;
        getline(cin, line);  // 先讀取整行

        stringstream ss(line);  // 用stringstream拆
        string country;
        ss >> country;  // 讀取第一個字

        count[country]++;
    }

    for(auto x : count){
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}