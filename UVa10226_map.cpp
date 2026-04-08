#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();

    while(T--){
        map<string, int> count; // <- alphabetical order guaranteed here
        string tree;
        int total = 0;

        // 1. getline(cin, tree) : checks EOF
        // 2. tree != "" : checks blank line
        while(getline(cin, tree) && tree != ""){
            count[tree]++;
            total++;
        }

        cout << fixed << setprecision(4);
        // map doesnt support index like map[i]
        // range-based
        // with & : p is a REFERENCE - directly access, faster
        for(auto& p : count){
            cout << p.first << " " << (p.second * 100.0 / total) << "\n";
        }

        if(T > 0){
            cout << "\n";
        }
    }

    return 0;
}