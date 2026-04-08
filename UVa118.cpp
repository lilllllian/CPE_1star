#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <tuple>

using namespace std;

struct state{
    int x, y; //機器人當前的座標
    char dir; //機器人當前面向的方向(N, S, E, W)
};

int main() {
    int maxX, maxY;
    scanf("%d %d", &maxX, &maxY);
    
    //用tuple記錄掉落標記(x, y, dirIdx)
    set<tuple<int, int, int>> scent;
    
    state robot; //存放當前機器人的位置(x, y)和方向dir
    string instr; //用來存放這台機器人的指令字串，ex."RFFLFR"
    char buffer[110]; //指令最大長度100，多預留空間
    
    //順時針方向，方向對應：N = 0, E = 1, S = 2, W = 3
    string dirs = "NESW";
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    while(scanf("%d %d %c", &robot.x, &robot.y, &robot.dir) == 3){
        scanf("%s" ,buffer); //讀取指令字串，建議用char陣列
        instr = buffer; //要存到string再轉換
        
        int dirIdx = static_cast<int>(dirs.find(robot.dir)); //回傳robot.dir在字串裡的索引值
        bool lost = false; //記錄機器人是否掉落
        
        for(char c : instr){
            //dirIdx : N = 0, E = 1, S = 2, W = 3
            //%4：旋轉會讓數字加減1，但方向只有4種，必須循環
            if(c == 'L'){
                dirIdx = (dirIdx + 3) % 4; //左轉：減1 -> dirIdx - 1，避免出現負數 -> dirIdx + 3
            }else if(c == 'R'){
                dirIdx = (dirIdx + 1) % 4; //右轉：加1
            }else if(c == 'F'){
                //根據方向(dx, dy)計算下一步(nx, ny)
                int nx = robot.x + dx[dirIdx];
                int ny = robot.y + dy[dirIdx];
                
                if(nx < 0 || nx > maxX || ny < 0 || ny > maxY){
                    auto key = make_tuple(robot.x, robot.y, dirIdx);
                    
                    if(scent.count(key)){ //已有標記 -> 忽略這次指令
                        continue;
                    }else{ //沒標記 -> 新增scent並掉落新的機器人
                        scent.insert(key); //在(x, y, dirIdx)留下標記(scent.insert(key))
                        lost = true;
                        break; //結束這台機器人的指令處理
                    }
                }else{ //如果沒超出邊界 -> 安全移動，更新座標
                    robot.x = nx;
                    robot.y = ny;
                }
            }
        }
        printf("%d %d %c", robot.x, robot.y, dirs[dirIdx]);
        if(lost) printf(" LOST");
        printf("\n");
    }
    return 0;
}
