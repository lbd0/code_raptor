// 혱니 참고했습니다..
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    // 시간, 좌표, 로봇 수
    map<pair<int, pair<int, int>>, int> timestamp;
    
    for (const auto &r : routes)
    {
        // 시작 위치
        int x = points[r[0] - 1][0];
        int y = points[r[0] - 1][1];
        // 현재 시간
        int t = 0;
        
        ++timestamp[{t, {x, y}}];
        
        // 로봇 별 타임스탬프 찍기
        for (int i = 1; i < r.size(); ++i)
        {
            int tx = points[r[i] - 1][0];
            int ty = points[r[i] - 1][1];
            
            while (x != tx || y != ty)
            {
                if (x < tx) ++x;
                else if (x > tx) --x;
                else if (y < ty) ++y;
                else --y;
                
                // 다음 시간 기록
                ++timestamp[{++t, {x, y}}];
            } 
        }
    }
    
    for (const auto &t : timestamp)
    {
        if (t.second >= 2) ++answer;
    }
    
    return answer;
}
