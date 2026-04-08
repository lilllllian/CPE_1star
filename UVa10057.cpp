// 題意的A為中位數 
// -> 才能使(|X1 − A| + |X2 − A| + . . . + |Xn − A|)為最小值

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n){

        vector<int> a(n);  //用vector動態分配大小，用sort也會比教方便
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        
        int mid_value = a[n/2];
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(abs(a[i] - mid_value) == mid_value) count++;
        }
        
        cout << mid_value << " " << count << endl;
    }
    return 0;
}
