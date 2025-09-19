#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 질문하기 참고.

int dfs(int k, const vector<vector<int>>& dungeons, vector<bool>& visited, int clear)
{
    // 유저가 탐험한 최대 던전 수.
    int res = clear;
    
    for(int i=0; i<dungeons.size(); ++i)
    {
        // 방문한 적이 있거나, 최소 필요 피로도보다 현재 피로도가 낮으면 패쓰.
        if(visited[i] || dungeons[i][0] > k) continue;
        
        // 방문 체크.
        visited[i] = true;
        
        // 경로별 던전 수 구하고 최대값을 res에 저장.
        res = max(dfs(k-dungeons[i][1], dungeons, visited, clear+1), res);
        
        // 백트래킹 -> 완전 탐색을 위함. 다른 경로에서 또 던전 탐험할 수 있게 함.
        visited[i] = false;
    }
    
    return res;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    vector<bool> visited(dungeons.size(), false);
    
    return dfs(k, dungeons, visited, 0);
}
