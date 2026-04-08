/*
B2-Sequence條件：
  1. 數列本身是：都是正整數且遞增
  2. 所有「bi + bj（i ≤ j）」的和不能有任何重複
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    int tc = 0;
    while(cin >> N){
        tc++;
        bool isB2 = true;
        vector<int> num(N);
        
        for(int i = 0; i < N; i++){
            cin >> num[i];
            if(num[i] < 1){
                isB2 = false;
            }
        }

        for(int i = 0; i < N - 1; i++){
            if(num[i] >= num[i+1]){
                isB2 = false;
            } 
        }

        // 記錄各種 bi + bj 是否出現過
        bool used[20001] = {false};  // 0 ~ 20000（0不會用到）

        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){  // j = i，保證 i <= j
                int sum = num[i] + num[j];

                if(used[sum]){
                    isB2 = false;
                    break;
                } else {
                    used[sum] = true;
                }
            }
        }

        cout << "Case #" << tc << ": " << "It is ";
        if(!isB2){
            cout << "not a B2-Sequence.\n" << endl;
        } else {
            cout << "a B2-Sequence.\n" << endl;
        }
    } 
    return 0;
}

/*
bool陣列用法：
    bool a[5];  // 有5個bool：used[0] ~ used[4]
    
    a[0] = true;
    a[1] = false;
    if(a[0]){...};

    bool b[10] = {false}; // 常見初始化
    ＝
    bool b[10];
    for(int i = 0; i < 10; i++){
        bool[i] = false;
    }
*/