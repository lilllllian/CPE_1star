#include <iostream>
using namespace std;

// 求最大公因數
int gcd(int x, int y){
    int smallerNum = min(x, y); // 取較小的值當for迴圈邊界
    int max_gcd = 0;

    for(int i = 1; i < smallerNum + 1; i++){
        if(x % i == 0 && y % i == 0){  // 如果 x 和 y 可以同時被這個 i 整除
            max_gcd = max(max_gcd, i); // 第一次：1 = max(0, 1)
        }
    }
    return max_gcd;
}

int main(){
    int N;
    while(cin >> N && N != 0){
        int G = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j <= N; j++){
                G = G + gcd(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}