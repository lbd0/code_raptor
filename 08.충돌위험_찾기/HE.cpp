// 풀이 참고했습니다
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    map<pair<int, pair<int, int>>, int> logs; // 특정 시간 특정 좌표에 있는 로봇 수

    for (auto& route : routes) { // 시작 좌표 설정
        int x = points[route[0] - 1][0];
        int y = points[route[0] - 1][1];
        int t = 0; // 현재 시간
      
        logs[{t, {x, y}}]++;

        for (int i = 1; i < route.size(); i++) {
            int tx = points[route[i] - 1][0];
            int ty = points[route[i] - 1][1];

            while (x != tx || y != ty) {
                if (x < tx) 
                  x++;
                else if (x > tx)
                  x--;
                else if (y < ty)
                  y++;
                else
                  y--;
                logs[{++t, {x, y}}]++; // 다음 시간 기록
            }
        }
    }

    int answer = 0;
    for (auto& kv : logs)
        if (kv.second >= 2) // 같은 시간과 좌표에 로봇이 2대 이상 존재 = 충돌 위험
          answer++;
    return answer;
}
