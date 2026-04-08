//讀入 n, m；若 n = m = 0 則結束。
//逐行讀取地圖（. 或 *）。
//對每個非地雷格子計算 8 個相鄰格子的地雷數，輸出數字；地雷格輸出 *。
//輸出格式與題意相符。

#include <iostream>

using namespace std;

int main() {
    int n, m;
    int field_no = 0; //用來記錄「目前是第幾張地圖」
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<string> g(n);
        for(int i = 0; i < n; i++){
            cin >> g[i];
        }
        
        vector<string> out(n, string(m, '0'));
        //string(m, '0'): 建立一個長度為m的字串，每個字元都填'0'
        //vector<string> out(n, ...): 建立長度為n的vector，每個元素都是字串
        
        //direction for 8 neighbors
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};  //delta row:行的偏移量
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};  //delta col:列的偏移量
        
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                //判斷是不是地雷
                if(g[r][c] == '*'){
                    out[r][c] = '*';
                }
                //處理安全格子
                else{
                    int cnt = 0;
                    for(int k = 0; k < 8; ++k){
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        //(nr, nc):第k個鄰居的座標
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m){ //避免超出地圖邊界
                            if(g[nr][nc] == '*') ++cnt;
                        }
                    }
                    out[r][c] = char('0' + cnt);
                    //將數字轉成對應的字元存進輸出矩陣：ex.cnt = 3 -> '0' + 3 = '3'
                    //out是string（字元陣列），必須存放字元
                }
            }
        }
        
        ++field_no;
        if(field_no > 1) cout << "\n";
        cout << "Field #" << field_no << ":\n";
        for(int i = 0; i < n; i++){
            cout << out[i] << "\n";
        }
    }
    
    return 0;
}
