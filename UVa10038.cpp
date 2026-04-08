#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    while(cin >> n){
        //vector<>:動態陣列，可以自動管理大小
        
        vector<int> seq(n);
        for(int i = 0; i < n; i++){
            cin >> seq[i];
        }
        /* int n = 5; vector<int> seq(n);
         = vector<int> seq = {0, 0, 0, 0, 0};*/
                
        vector<bool> diff(n, false); //建立一個長度為n的布林向量diff，初始值全是false
        for(int i = 1; i < n; i++){
            int d = abs(seq[i] - seq[i-1]); //abs():取絕對值
            if(d >= 1 && d <= n-1){
                diff[d] = true;
            }
        }
        
        bool jolly = true; //先假設這個序列是jolly
        for(int i = 1; i < n - 1; i++){
            if(!diff[i]){  //如果差值出現(diff[i] == false)
                jolly = false; //就不是jolly
                break; //跳出迴圈，無需繼續檢查
            }
        }
        
        if(jolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}
