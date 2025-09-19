// 풀이 참고했습니다
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

void dfs(int k, vector<vector<int>> dungeons, vector<bool> visited, int cnt) {
    answer = max(answer, cnt);  // 최대 탐험 수

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {  // 아직 방문하지 않았으며 최소 필요 피로도 충족될 경우
            visited[i] = true; // 방문 처리
            dfs(k - dungeons[i][1], dungeons, visited, cnt + 1); // 피로도 차감, 탐험 수 증가
            visited[i] = false; // 다시 초기화
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, visited, 0);
    return answer;
}
