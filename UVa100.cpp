// 題目：沒有說明 i 一定小於 j（0 < i，j < 1,000,000）

#include <iostream>
#include <algorithm>  // max
using namespace std;

int main(){
    int i, j;
    while(cin >> i >> j){
        // 如果 i > j，i 和 j 數值交換
        bool swapIJ = false;
        if(i > j){
            swap(i, j);
            swapIJ = true;
        }

        int max_cycleLength = 1;

        for(int n = i; n <= j; n++){
            int cycleLength = 1;

            // if(n == 1) break; 
            // -> 如果 i = 1，會跳出for迴圈，導致後面的n沒算到

            int n1 = n;
            while(n1 != 1){
                if(n1 % 2 == 1){
                    n1 = 3*n1 + 1;
                } else {
                    n1 = n1 / 2;
                }
                cycleLength++;
            }

            max_cycleLength = max(max_cycleLength, cycleLength);
        }

        // 如果 i 和 j 交換過，再換回來
        if(swapIJ) swap(i, j);

        cout << i << " " << j << " " << max_cycleLength << endl;
    }
}