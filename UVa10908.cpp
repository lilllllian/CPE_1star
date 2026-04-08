// 關鍵觀念：「以給定格子為中心，往外長正方形」
// -> 一直擴大，直到超出邊界或遇到不同字元

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int M, N, Q;
        cin >> M >> N >> Q; // M x N dimension of the grid, Q queries

        // The grid：(The value of M and N will be at most 100)
        char grid[101][101];  // char：題目用a, b, c, ...
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> grid[i][j];
            }
        }

        cout << M << " " << N << " " << Q << "\n";
        
        // The lines
        while(Q--){
            int r, c;
            cin >> r >> c;
            
            char center = grid[r][c];  // 中心字元
            int edge_length = 1; // 最小是只有中心字元一個
            int d = 1;  // 向外擴一圈的距離，每跑完一次下方程式，d++

            // 檢查這圈會不會超出地圖邊界
            /*if(r - d < 0 || r + d >= M || c - d < 0 || c + d >= N){
                break;
            }*/

            bool same = true;

            while(same == true){
                for(int j = c - d; j <= c + d; j++){
                    if(grid[r - d][j] != center || grid[r + d][j] != center){
                        same = false;
                    }
                }

                for(int i = r - d; i <= r + d; i++){
                    if(grid[i][c - d] != center || grid[i][c + d] != center){
                        same = false;
                    }
                }

                if(!same) break;

                edge_length = 2*d + 1;
                d++;
            }

            cout << edge_length << endl;
        }
    }
    return 0;
}