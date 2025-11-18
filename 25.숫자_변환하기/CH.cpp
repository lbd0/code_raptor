#include <queue>
#include <vector>

using namespace std;

// 역방향 BFS 알고리즘
int solution(int x, int y, int n) {
    queue<pair<int, int>> que;              // 현재 y와 비용
    vector<bool> visited(y + 1, false);     // 최소 비용 비교
    
    int answer = 0;
    
    que.push({y, 0});
    visited[y] = true;
    
    while (!que.empty()) {
        auto [cur, cost] = que.front(); que.pop();
        
        // x와 y가 같다면 비용 반환
        if (cur == x) return cost;
        
        // 1. cur - n
        int next = cur - n;
        // x보다 작고 나온 적 없다면
        if (next >= x && !visited[next]) {
            visited[next] = true;
            que.push({next, cost + 1});
        }
        
        // 2. cur / 2
        if (cur % 2 == 0) {
            next = cur / 2;
            if (next >= x && !visited[next]) {
                visited[next] = true;
                que.push({next, cost + 1});
            }
        }
        
        // 3. cur / 3
        if (cur % 3 == 0) {
            next = cur / 3;
            if (next >= x && !visited[next]) {
                visited[next] = true;
                que.push({next, cost + 1});
            }
        }
    }

    return -1;
}
