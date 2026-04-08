// 尋找 S1 和 S2 的公因數 L（大於 1）
// 把 S1, S2 當成二進位整數，它們的 gcd（最大公因數）是否大於 1

#include <iostream>
using namespace std;

long long binToInt(const string &s){
    long long x = 0;
    for(char c : s){
        x = x*2 + (c - '0');  // 左移一位 + new bit
    }
    return x;
}
// &s：reference，s是一個別名，指向呼叫者傳進來的那個字串，不會再另外複製一份
// const：不能被改動（ex. 不能寫 s[0] = '1')

int main(){
    int N;
    cin >> N;
    int tc = 0;
    while(N--){
        string s1, s2;
        cin >> s1 >> s2;

        tc++;

        long long num1 = binToInt(s1);
        long long num2 = binToInt(s2);

        int gcd_num = 1;

        // 1. 歐幾里得算法
        // -> gcd(a, b) = gcd(b, a % b)，一直到 b = 0，此時 a 就是 gcd
        while(num2 != 0){
            long long r = num1 % num2;
            num1 = num2;  // num1：最大公因數
            num2 = r;
        }
        gcd_num = num1;

        /*
        // 2. 我的算法 -> Time Limit Exceed
        if(num1 > num2) swap(num1, num2);

        for(int i = 1; i <= num1; i++){
            // 如果 i 能同時整除 num1 和 num2，i 就是其中一個公因數
            if(num1 % i == 0 && num2 % i == 0){ 
                gcd_num = max(gcd_num, i);  // 找出最大公因數
            } 
        }
        */
        

        // 題意：公因數 L > 1
        if(gcd_num > 1){
            cout << "Pair #" << tc << ": All you need is love!" << endl;
        } else {
            cout << "Pair #" << tc << ": Love is not all you need!" << endl;
        }
    }
    return 0;
}

/*
string s : 
    1. cin >> s : 讀一個「沒有空白」的字串
    2. getline(cin, s) : 讀到這一整行的內容（包含空白），直到 '\n' 結束
*/