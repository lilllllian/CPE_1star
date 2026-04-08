#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(int n){
    int count = 0;

    // 判斷質數只需數到「根號Ｎ」，如果 n 可以被這個 i 整除，一定會有相對應的另一個數
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0) count++;
    }

    if(count == 1) return true;
    else return false;
}

int reverseNum(int n){
    int re = 0;

    while(n > 0){
        int digit = n % 10;   // 1. 取出個位數 
        re = re*10 + digit;   // 2. 把個位數加到 reN 的最後面
        n = n / 10;           // 3. 去掉 x 的個位數
    }

    return re;
}

int main(){
    int N;
    while(cin >> N){
        bool isPrime = isPrimeNum(N);

        if(!isPrime){
            cout << N << " is not prime." << endl;
        } else {
            int reN = reverseNum(N);
            bool isEmirp = isPrimeNum(reN);

            if(!isEmirp || N == reN){
                cout << N << " is prime." << endl;
            } 
            else{
                cout << N << " is emirp." << endl;
            }
        }
    }
    return 0;
}