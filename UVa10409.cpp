#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        int top = 1, north = 2, west = 3;

        while(n--){
            string dir;
            cin >> dir;

            int new_top = top, new_north = north, new_west = west;

            if(dir == "north"){
                new_top = north;
                new_north = 7 - top;  // new_north = bottom
                // west unchanged
            } else if (dir == "south"){
                new_top = 7 - north;  // south + north = 7
                new_north = top;
                // west unchanged
            } else if (dir == "east"){
                new_top = 7 - west;   // west + east = 7
                new_west = top;
                // north unchanged
            } else if (dir == "west"){
                new_top = west;
                new_west = 7 - top;  // new_west = bottom
                // north unchanged
            }

            // Save the updated value
            top = new_top;
            north = new_north;
            west = new_west;
        }

        cout << top << "\n";
    }

    return 0;
}