// 負數餘數：在C++裡，%出來的餘數會跟被除數同號

/*
1. 重複讀入一組 N, M（有 N 和 M 輸入，且 N 和 M 都不為 0）
2. 讀入 N 個整數，用 vector 記錄數字（num）和餘數（remaining）
3. 用 bubble sort 排序（雙層for迴圈，範圍跑到 N-1）
   a. 先比兩個數的餘數
   b. 如果餘數相同，在看奇偶與大小
*/

#include <iostream>
#include <vector>
#include <algorithm>  // sort
using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){  // 處理一組Ｎ和Ｍ
        cout << N << " " << M << "\n";

        if(N == 0 && M == 0){
            break;
        }

        vector<int> num;
        for(int i = 0; i < N; i++){
            int n;
            cin >> n;
            num.push_back(n);
        }

        // sort(起點iterator, 結尾iterator, 比較函式);
        // [&](int x, int y)：[捕捉列表](參數列表) {函式本體}
        sort(num.begin(), num.end(), [&](int x, int y){
            int rx = x % M;
            int ry = y % M;

            // 1. 餘數不同：小的在前，大的在後
            if(rx != ry) return rx < ry;

            // 2. 餘數相同：處理奇偶和大小
            bool x_odd = (x % 2 != 0);
            bool y_odd = (y % 2 != 0);

            // 一奇一偶：奇數在前，偶數在後
            if(x_odd != y_odd){
                return x_odd > y_odd;  // x_odd == true 排在前面
            }

            // 兩個奇數：大的在前
            if(x_odd && y_odd){
                return x > y;
            } 
            
            // 兩個偶數：小的在前
            return x < y;
        });

        cout << N << " " << M << endl;

        for(int num_out : num){
            cout << num_out << endl;
        }

    }
    return 0;

}

// bubble sort：只要 a[j] > a[j+1] 就交換
/*
for(int i = 0; i < N; i++){
    int n;
    cin >> n;
    num.push_back(n);

    int r = n % M;
    remaining.push_back(r);
}
for(int i = 0; i < N - 1; i++){  // 只需要跑到 N-1
    for(int j = 0; j < N - 1; j++){
        // 餘數不相同：於數小到大排列
        if(remaining[j] != remaining[j+1]){
            if(remaining[j] > remaining[j+1]){
                // remaining陣列比較餘數大小，並交換順序
                int tmpR = remaining[j];
                remaining[j] = remaining[j+1];
                remaining[j+1] = tmpR;

                // num陣列的順序也跟著交換
                int tmpN = num[j];
                num[j] = num[j+1];
                num[j+1] = tmpN;
            }
        } 

        // 餘數相同：用num的奇偶關係排列
        else {
            // 一奇一偶
            if(num[j] % 2 != num[j+1] % 2){
                if(num[j] % 2 == 0){
                    int tmpN2 = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmpN2;
                }
            }

            // 兩個奇數
            else if(num[j] % 2 != 0 && num[j+1] % 2 != 0){  // 判斷奇偶用 != 0，避免負奇數
                if(num[j] < num[j+1]){
                    int tmpN2 = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmpN2;
                }
            }

            // 兩個偶數
            else{
                if(num[j] > num[j+1]){
                    int tmpN2 = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmpN2;
                }
            }
        }
    }
}
*/