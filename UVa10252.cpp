/* 
1. 建立兩個陣列，並初始化為 0
2. 對陣列裡存的每個字母出現的共同次數做 min -> algorithm
3. 把這個字母重複 append 到答案字串
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        int cntS1[26] = {0};
        int cntS2[26] = {0};

        for(char c1 : s1){  // c1：數字，字元的 ASCII code
            if(c1 >= 'a' && c1 <= 'z'){  // 'a' = 97, 'z' = 122
                cntS1[c1 - 'a']++;  // c1 - 'a'：陣列的index（0 ~ 26）
            }
        }

        for(char c2 : s2){
            if(c2 >= 'a' && c2 <= 'z'){
                cntS2[c2 - 'a']++;
            }
        }

        // string 裡的元素型別固定是 char
        string ans;  // 建構答案字串
        for(int i = 0; i < 26; i++){
            // common：兩個字串中，這個字母最多可以當幾次交集
            int common = min(cntS1[i], cntS2[i]); 
            while(common--){  // 當 common = 0，跳出迴圈
                ans.push_back('a' + i);  // 索引(int) -> 字元(char)
            }

        }

        cout << ans << endl;
    }
    return 0;
}

/*
    c - 'a' : 字元 -> 索引（char -> int)
    -> 把「某個字母」變成「第幾個字母」

    'a' + i : 索引 -> 字元（int -> char）
    -> 從「第幾個字母」變回「哪個字母」
*/
