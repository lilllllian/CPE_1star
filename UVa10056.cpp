// N:玩家數, p:單次成功的機率, i:獲勝玩家的序列
/*第i號玩家第一次機會是在第i次（前面的人1 ~ i-1），若沒成功，再＋N次是下一次機會*/
/*要第i人在第k次機會成功（k=0:第一次機會）：
  i. 在k之前都失敗的機率（1-p）＾（i-1 + k*N）-> 這輪前i-1人＋前k輪所有人
 ii. 這次成功的機率 p
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    int S;
    cin >> S;
    const double EPS = 1e-12;
    while(S--){
        int N, i;
        double p;
        cin >> N >> p >> i;
        
        // 特殊情況處理
        if(p <= EPS){ // p == 0，永遠不會成功
            printf("0.0000\n");
            continue;
        }
        
        if(p >= 1.0 - EPS){ // p == 1。第一次投擲必成功，只有第1名能贏
            double res = (i == 1)? 1.0 : 0.0;
            printf("%.4f\n", res);
            continue;
        }
        
        double q = 1.0 - p; // 失敗的機率
        double P = p * pow(q, i - 1) / (1.0 - pow(q, N));
        
        printf("%.4f\n", P);
    }
    return 0;
}
