// vector是動態大小，要用push_back()動態加入元素

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    // 生成費波那契數列，直到其超過100,000,000
    vector<int> fib = {1,2};  // 數列的起始是{1, 2}
    while(fib.back() <= 100000000){  
        // 下一個費波那契數字：最後一個元素＋倒數第二個元素
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }  

    while(N--){
        int dec_base;
        cin >> dec_base;

        cout << dec_base << " = ";

        // fib_base：大小和 fib 一樣，用來儲存每個 Fibonacci numbers 是否被用來表示目標數字（dec_base）
        vector<int> fib_base(fib.size(), 0);  // 初始化為0

        int remaining = dec_base;
        // 從 Fibonacci sequence 最大的數字開始，檢查是否可以用這個數字表示dec_base
        for(int i = fib_base.size() - 1; i >= 0; i--){
            if(remaining >= fib[i]){  // remaining >= fib[i]：可以用此 fibonacci num 來表示remaining
                fib_base.push_back(1);  // 1：此 fibonacci num 有被使用
                remaining = remaining - fib[i];  // remaining：當前剩餘的數字
            }
            else{
                fib_base.push_back(0);  // 0：此 fibonacci num 沒有被使用
            }
        }

        bool started = false;  // 用來避免前綴（第一個）0
        for(int i = 0; i < fib_base.size(); i++){
            if(fib_base[i] == 1 || started == true){
            cout << fib_base[i];
            started = true;
            }
        }
        
        cout << " (fib)" << endl;
    }
    return 0;
}