// size_t：整數型別，用來放大小、長度、索引 -> 無號整數
// -> ex., string.length()、vector.size()...

#include <iostream>
#include <string>
using namespace std;

int main(){
    string keyboard = "qwertyuiop[]asdfghjkl;'zxcvbnm,.";
    string line;
    while(getline(cin, line)){
        for(char &c : line){  // ！...加＆：改 c 才會改到 line 的內容...!
            if(c == ' '){
                continue;  // 空白直接跳過
            }
            else{
                size_t pos = keyboard.find(c);  // 在字串 keyboard 中，找等於 ch 的位置，回傳它的index（從0開始）
                c = keyboard[pos - 2];
            }
        }
        cout << line << endl;
    }
    return 0;
}