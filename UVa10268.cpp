/*
一直讀input x
    讀一整行係數       // getline(cin, sth)
    把係數拆成很多整數  // stringstream ss(sth)
    算導數            // Horner's method
    輸出答案
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    long long x;
    while(cin >> x){
        cin.ignore();

        string line;
        getline(cin, line);  // second line 的數量不固定

        stringstream ss(line);
        
        vector <long long> a;
        long long num;  // num : each coefficient

        while(ss >> num){
            a.push_back(num);
        }

        int n = a.size() - 1;  // n：最高次方

        long long ans = 0;

        // 從最高次方開始計算
        // 用 Horner's method 計算倒數多項式的值，避免使用 pow() 產生浮點誤差
        // 導數多項式：a[0]*n * x^(n-1)  +  a[1]*(n-1) * x^(n-2)  +  ...  +  a[n-1]*1
        for(int i = 0; i < n; i++){
            ans = ans * x + a[i] * (n - i);
            // current coefficient(導數後的係數）：a[i] * (n - i)
        }

        cout << ans << endl;
    }
}