#include <iostream>
using namespace std;

int main(){
    long long S, D;  // S：1 ~ 10000, D：1 ~ 10^15
    while(cin >> S >> D){
        while(D > S){
            D = D - S;  // 還要往後數幾天
            S++;  // 換下一團
        }
        cout << S << endl;
    }
    return 0;
}