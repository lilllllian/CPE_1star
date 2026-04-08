// Warn:把long long強制轉成int((int) N)，當N超過int範圍時會溢位
// -> 用long long全程處理，避免整數截斷問題
//numLL:long long類型常數，告訴編譯器，即使數字本身比int或long的範圍大，也應以long long型處理

#include <iostream>
#include <iomanip> //for setw(4)
using namespace std;

int main() {
    long long N;
    int tc = 0;

    while(cin >> N){
        tc++;
        cout << setw(4) << tc << ". ";  //題目要求case number要佔4格、靠右
        int k_num, l_num, h_num, s_num;
        if(N >= 10000000LL){
            k_num = N / 10000000LL;
            N = N % 10000000LL;
            cout << k_num << " " << "kuti ";
        }
        
        if(N >= 100000LL){
            l_num = N / 100000LL;
            N = N % 100000LL;
            cout << l_num << " " << "lakh ";
        }
        
        if(N >= 1000LL){
            h_num = N / 1000LL;
            N = N % 1000LL;
            cout << h_num << " " << "hajar ";
        }
        
        if(N >= 100LL){
            s_num = N / 100LL;
            N = N % 100LL;
            cout << s_num << " " << "shata ";
        }
        
        if(N > 0){
            cout << N << endl;
        }
    }
    return 0;
}
