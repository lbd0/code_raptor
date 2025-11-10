#include <string>
#include <unordered_set>
using namespace std;

// unordered_set에 사용할 hash 함수.
struct pathHash {
    size_t operator()(const pair<pair<int,int>, pair<int,int>>& path) const {
        size_t h1 = path.first.first * 31 + path.first.second;
        size_t h2 = path.second.first * 31 + path.second.second;
        return h1 * 31 + h2;
    }
};

int solution(string dirs) {
    int answer = 0;
    
    // 시작 위치.
    int x=0, y=0;
    
    // 시작 좌표, 끝 좌표 & 끝 좌표, 시작 좌표 저장. 중복은 저장 X.
    unordered_set<pair<pair<int, int>, pair<int, int>>, pathHash> path;
    
    for(const auto& d:dirs)
    {
        pair<int, int> start = {x, y};
        
        if(d == 'U')
        {
            if(y == 5) continue;
            
            y++;
        }
        else if(d == 'D')
        {
            if(y == -5) continue;
            
            y--;
        }
        else if(d == 'R')
        {
            if(x == 5) continue;
            
            x++;
        }
        else if(d == 'L')
        {
            if(x == -5) continue;
            
            x--;
        }
        
        pair<int, int> end = {x, y};
        
        path.insert({start, end});
        path.insert({end, start});
    }
    
    // 맵의 크기에서 /2 => 시작점+끝점, 끝점+시작점으로 저장했기 때문!
    answer = path.size()/2;
    
    return answer;
}
