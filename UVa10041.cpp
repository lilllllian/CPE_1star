//最佳的位置就是這些數字的「中位數」
/*✨ 為什麼是中位數？
如果你選在小於中位數的地方，往右移會減少右邊比較多親戚的距離總和。
如果你選在大於中位數的地方，往左移會減少左邊比較多親戚的距離總和。
唯有在中位數時，左右親戚數量平衡，距離和才會最小。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    while(N--){
        int r;
        scanf("%d", &r);
        vector<int> house(r); //建立一個大小為r的vector<int>，裡面已經有r個元素
        for(int i = 0; i < r; i++){
            scanf("%d", &house[i]);
        }
        
        sort(house.begin(), house.end()); //把整個vector<int> house由「小到大」排序
        /* house.begin():回傳指向第一個元素的iterator
           house.end():回傳指向「最後一個元素的下一個位置」的iterator
           sort(first, last):會對[first, last]這個範圍內的元素排列 */
        
        int median = house[r/2];
        
        int sum = 0;
        for(int i = 0; i < r; i++){
            sum += abs(house[i] - median); 
        }
        
        cout << sum << endl;
    }
    return 0;
}
