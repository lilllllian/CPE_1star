#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string s;
    bool is_firstline = false;
    while(getline(cin, s)){
        if(!is_firstline) is_firstline = true;
        else cout << endl;
        int freq[130] = {};
        int max_num = 0;
        for(char c : s){
            freq[c]++;
            max_num = max(max_num, freq[c]);
        }
        
        for(int i = 1; i <= max_num; i++){  //次數1開始跑到max_num
            for(int j = 128; j >= 32; j--){
                if(i == freq[j]){
                    cout << j << " " << i << "\n";
                }
            }
        }
    }
    return 0;
}
