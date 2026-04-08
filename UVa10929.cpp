// 11 的倍數：奇數位和偶數位的差的絕對值為 0 或 11 的倍數

#include <iostream>
using namespace std;

int main(){
    string N;
    while(getline(cin, N)){
        bool isO = true;
        int totalO = 0;
        int totalE = 0;

        for(int num : N){
            num = num - '0';  // 變成 0 ~ 9

            if(isO){
                totalO += num;
                isO = false;
            } else {
                totalE += num;
                isO = true;
            }
        }

        if(totalE > totalO){
            swap(totalE, totalO);
        }

        if((totalO - totalE) % 11 == 0){
            cout << N << " is a multiple of 11." << endl;
        } else {
            cout << N << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}