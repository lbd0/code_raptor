#include <string>
#include <vector>
#include <map>
using namespace std;

// gpt 도움으로 아이디어 생각해 냄!!
// map의 키로 시간+좌표 저장하고, 값으로 횟수 저장 -> 값이 2이상이면 2대 이상 같은 시간, 같은 좌표에 있었던 것.

// 시간 + 좌표로 키값 저장하기 위한 구조체.
struct Key
{
    int t, r, c;
    
    bool operator< (const Key& other) const
    {
        if(t != other.t) return t < other.t;
        if(r != other.r) return r < other.r;
        return c < other.c;  
    }
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    // 시간+좌표를 키값으로 갖는 맵.
    map<Key, int> time_line;    
    
    for(const auto& rou:routes)
    {
        int time = 0;
        int r = points[rou[0]-1][0];
        int c = points[rou[0]-1][1];
        
        // 시작 위치에서도 충돌위험 확인.
        time_line[{time, r, c}]++;
        
        // 최단 경로로 이동하면서 맵에 저장.
        for(int i=1; i<rou.size(); ++i)
        {
            int dr = points[rou[i]-1][0];
            int dc = points[rou[i]-1][1];
            
            // 문제 규칙 4번에 따라 r좌표 먼저 이동하고, c좌표 이동.
            while(r != dr)
            {
                r += (dr - r) > 0 ? 1:-1;
                time++;
                time_line[{time, r, c}]++;
            }
            
            while(c != dc)
            {
                c += (dc - c) > 0 ? 1:-1;
                time++;
                time_line[{time, r, c}]++;
            }
        }
    }
    
    // 맵에서 value 값이 2 이상이면 충돌 위험 횟수 증가.
    for(const auto& t:time_line)
    {
        if(t.second >= 2) answer++;
    }
    
    return answer;
}
