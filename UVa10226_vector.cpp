#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // ✅ faster I/O
    cin.tie(NULL);                    // ✅ decouple cin and cout

    int T;
    cin >> T;
    cin.ignore(); // Consume '\n' after T
    cin.ignore(); // Consume the blank line separating T from first test case

    while(T--){
        // Each pair stores : {species name, count}
        vector<pair<string, int>> species;
        string tree;
        int total = 0;

        // Read tree names line by line until a blank line or EOF
        while(getline(cin, tree) && tree != ""){
            bool found = false;
            for(int i = 0; i < species.size(); i++){
                if(species[i].first == tree){
                    species[i].second++; // Species exits, count++
                    found = true;
                    break;  // No need to keep searching
                } 
            }

            // Species not found, add it to the vector with count 1
            if(!found){
                species.push_back({tree, 1});
            }
            total++;
        }

        // Sort vector alphabetically by species name 
        sort(species.begin(), species.end());

        cout << fixed << setprecision(4);
        for(int i = 0; i < species.size(); i++){
            cout << species[i].first << " " 
                 // << fixed << setprecision(4) 
                 << (species[i].second * 100.0 / total) << "\n";
        }

        // Print blank line between test cases (not after the last one)
        if(T > 0){
            cout << "\n";
        }
    }

    return 0;
}