// 9-degree：把各位數相加，重複做幾次才變成9
// 用「string」：最大數字（1000位數）會超過long long範圍

#include <iostream>
using namespace std;

int main(){
    string N;
    while(getline(cin, N) && N != "0"){
        int sum = 0;
        int degree = 0;

        // sum：每位數（N）的相加
        for(char c : N){
            sum = sum + (c - '0');  //ex. '5' - '0' = 5
        }

        // 先判斷 sum 是否為9的倍數
        if(sum % 9 != 0){
            cout << N << " is not a multiple of 9." << endl;
            continue; // 不是 -> 跳回 getline(cin, N)
        }

        degree = 1;  // 第一次相加：for(char c : N)

        // 把 sum 的每個位數相加，直到等於 9
        while(sum != 9){
            int x = sum;
            int sum1 = 0;
            while(x != 0){
                sum1 = sum1 + (x % 10);
                x = x / 10;
            }
            sum = sum1;
            degree++;
        }
        cout << N << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
    }
    return 0;
}

// long long 版本
/*int main(){
    long long N;
    while(cin >> N && N != 0){
        long long x = N;
        int sum = 0;
        int degree = 0;

        // 題目：每位數(N位)的總和相加(sum) -> 不是把位數相加到剩一位
        while(x != 0){  
            sum = sum + (x % 10);
            x = x / 10;
        } 

        cout << sum << "\n";

        // 先判斷總和不是9的倍數的情況
        if(sum % 9 != 0){
            cout << N << " is not a multiple of 9." << endl;
            continue;  // 跳回 while(cin >> N)
        }

        // 確定是9的倍數 -> 開始算9-degree
        degree = 1; // 第一次：Ｎ -> sum

        // 如果 sum 不是9，位數就一直相加到等於 9 
        while(sum != 9){
            int y = sum;
            int sum1 = 0;
            while(y != 0){
                sum1 = sum1 + (y % 10);
                y = y / 10;
            }
            sum = sum1;
            degree++;
        }
        cout << N << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
    }
    return 0;
}*/