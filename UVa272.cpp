#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    bool open = true; //true = 下一個 ” 是開頭 → `` ，false = 結尾 → ‘’
    while(getline(cin, line)){ //一次讀一行直到EOF
        for(char c : line){    //逐字元掃描
            if(c == '"'){
                if(open){
                    cout << "``";
                }else{
                    cout << "''";
                }
                open = !open;
            }else{
                cout << c;
            }
        }
        cout << "\n";          //getline不會保留換行 → 手動補上
    }
    return 0;
}
