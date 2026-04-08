// ! Time Limit Exceeded

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n <= 0 || m <= 0){
            cout << "Boring!" << endl;
            continue;
        }

        vector<int> a;
        a.push_back(n);

        bool ok = true;

        for(int i = 1; ;i++){
            // a[i - 1]是當前數字
            if(a[i - 1] == 1) break;  // 到 1 就停止

            if(a[i - 1] % m != 0){  // 不能整除就失敗
                ok = false;
                break;
            }

         // a[i] = a[i - 1] / m; 
         // -> 一開始 a[1] 還不存在，會導致越界存取(out of bounds) 

            int nxt = a[i - 1] / m;  // 算出下一個數字
            a.push_back(nxt);
        }

        if(!ok){
            cout << "Boring!";
        } else {
            for(int i = 0; i < a.size(); i++){
                cout << a[i] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}