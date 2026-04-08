#include <iostream>
#include <string>

using namespace std;

int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
string date[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main()
{
   int T, m, d;
   scanf("%d", &T);

   while(T--){
       scanf("%d%d", &m, &d);
       int delta = (d - doom[m]) % 7; //計算「輸入日期」相對於該月末日的天數差
       if(delta < 0) delta += 7; //如果是負的，就加回7 → 避免陣列索引錯誤
       cout << date[delta] << "\n";
   }

   return 0;
}
