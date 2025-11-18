#include <string>
#include <vector>
#include <queue>

using namespace std;
// BFS
int solution(int x, int y, int n) {
    // 현재 값, 연산 횟수 저장.
    queue<pair<int, int>> q;
    
    // 방문 표시.
    vector<bool> visited(y+1, false);
    
    q.push({x, 0});
    visited[x] = true;
    
    while(!q.empty())
    {
        int value = q.front().first, count = q.front().second;
        q.pop();
        
        if(value == y) return count;
        
        int next_values[3] = { value + n, value * 2, value * 3 };
        
        for(auto& n:next_values)
        {
            if(n <= y && !visited[n])
            {
                visited[n] = true;
                q.push({n, count+1});
            }
        }
        
    }
    
    return -1;
}
