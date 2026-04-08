#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int s, d;
        cin >> s >> d;

        int a, b;
        
        a = (s + d) / 2;  // 聯立方程式：a + b = s 、 a - b = d
        b = s - a;
        

        if(a >= 0 && b >= 0 && abs(a - b) == d){  // score >= 0
            cout << a << " " << b << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}