#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    // 오, 아, 왼, 위 이동을 위한 좌표
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    // 방향을 지정할 dir, 좌표 x, y
    int dir = 0, x = 0, y = 0;
    
    // 1 ~ n*n까지 반복
    for (int i = 1; i <= n * n; ++i)
    {
        // x, y 좌표에 i 넣기
        answer[x][y] = i;
        
        // 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 범위를 벗어나거나 도달한 곳이 0이 아니면
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || answer[nx][ny] != 0)
        {
            // 방향 전환
            dir = (dir + 1) % 4;
            
            // 전환한 방향으로 nx, ny 값을 다시 변경
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        // x, y에 이동할 위치 저장
        x = nx;
        y = ny;
    }
    
    return answer;
}
