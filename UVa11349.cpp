//使用 64-bit 整數（long long），因為題目元素範圍可達 ±2^32。
//若有任一元素為負數，立即判定為 Non-symmetric。
//只需檢查一半位置以節省比較次數。

#include <iostream>

using namespace std;

int main() {
    int T;
    scanf("%d",&T); //if(!(cin >> T)) return 0;
    for(int tc = 1; tc <= T; ++tc){  //tc：test case 測資
        int n;
        scanf("%d", &n); //cin >> n;
        
        //宣告一個 nxn 的二維向量，用來存放矩陣元素
        vector<vector<long long>> M(n, vector<long long>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; j++){
                scanf("%lld", &M[i][j]); //cin >> M[i][j];
            }
        }
        
        bool symmetric = true;  //先假設這個矩陣是對稱的
        for(int i = 0; i < n && symmetric; ++i){
            for(int j = 0; j < n; ++j){
                if(M[i][j] < 0){  //條件1：若有任何元素<0
                    symmetric = false;
                    break;
                }
                int ri = n - 1 - i; //「中心對稱」對應的行索引
                int rj = n - 1 - j; //「中心對稱」對應的列索引
                
                //條件2：檢查當前元素和它中心對應位置的值是否相同
                if(M[i][j] != M[ri][rj]){
                    symmetric = false;
                    break;
                }
            }
        }
        
        cout << "Test #" << tc << ": ";
        if(symmetric) cout << "Symmetric\n";
        else cout << "Non-symmetric\n";
        //printf("Test #%d: %s\n", tc, symmetric ? "Symmetric" : "Non-symmetric");
    }
    return 0;
}
