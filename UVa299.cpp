#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int L;
        cin >> L;
        
        // Read the card order as a whole line
        string cur_order;
        getline(cin >> ws, cur_order); // cin >> ws discards the leftover newline from "cin >> L"

        // Parse space-separated integers from the line into a vector
        stringstream ss(cur_order);
        vector<int> ord;
        int x;
        while(ss >> x) ord.push_back(x);


        // Bubble Sort
        int count = 0;
        for(int i = 0; i < ord.size(); i++){
            for(int j = i + 1; j < ord.size(); j++){
                if(ord[i] > ord[j]){
                    swap(ord[i], ord[j]);
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
    }
    return 0;
}