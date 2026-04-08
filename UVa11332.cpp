#include <iostream>
using namespace std;

int main(){
    long long n;  // n：1 ~ 2,000,000,000
    while(cin >> n && n != 0){
        // 一直做f(n)，把位數加起來，直到n變成一位數
        while(n >= 10){
            int sum = 0;
            long long x = n;  // 用x來拆位數，不要直接動到num
            
            while(x > 0){ 
                sum = sum + (x % 10);  // 拿x的個位數加到sum
                x = x / 10;  // 去掉個位數
            }
            n = sum;  // 把n換成這次的位數和
        }
        cout << n << endl;
    }
    return 0;
}