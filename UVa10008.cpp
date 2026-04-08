#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    int count[26] = {0};
    char letter[26];  // 存字母

    for(int i = 0; i < 26; i++){
        letter[i] = 'A' + i;  // letter = A + B + C + .....
    }

    while(n--){
        string s;
        getline(cin, s);

        for(char c : s){
            if(c >= 'A' && c <= 'Z'){
                count[c - 'A']++;
            } else if(c >= 'a' && c <= 'z'){
                count[c - 'a']++;
            }
        }
    }

    // Bubble Sort：比較兩個元素，順序錯就交換
    // 次數多的在前 / 次數一樣 -> 字母小的在前
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 26; j++){
            if(count[i] < count[j] || count[i] == count[j] && letter[i] > letter[j]){
                swap(count[i], count[j]);
                swap(letter[i], letter[j]);
            }
        }
    }

    for(int i = 0; i < 26; i++){
        if(count[i] > 0){
            cout << letter[i] << " " << count[i] << endl;
        }
    }

    return 0;
}