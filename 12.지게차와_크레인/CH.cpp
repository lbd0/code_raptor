#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void crane(vector<string> &storage, const char &ch)
{
    // ch와 같은 컨테이너 .으로 변경
    for (auto &st : storage) 
        replace(st.begin(), st.end(), ch, '.');
}

void fork(vector<string> &storage, const char &ch)
{
    int n = storage.size();
    int m = storage[0].size();
    
    // storage와 같은 크기로 방문 여부를 저장할 vector 생성
    // 중복 탐색을 방지하기 위함
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // BFS를 구현하기 위한 queue
    // 처음 시작하는 지점(외곽에서 접근 가능한 칸)을 넣음
    queue<pair<int, int>> que;
    
    // 1. 외곽에서 접근 가능한 칸 탐색
    // 왼쪽, 오른쪽
    for (int i = 0; i < n; ++i)
    {
        // j를 0과 m-1만 반복
        for (int j : {0, m - 1})
        {
            // 현재 칸이 비어있거나 ch와 같은 컨테이너이고, 방문하지 않았다면
            if (storage[i][j] == '.' && !visited[i][j])
            {
                // queue에 위치를 넣고, 방문 표시
                que.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    
    // 위쪽, 아래쪽
    for (int j = 0; j < m; ++j)
    {
        for (int i : {0, n - 1})
        {
            if (storage[i][j] == '.' && !visited[i][j])
            {
                que.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    
    // 상하좌우 탐색을 위한 배열
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // 2. BFS
    while (!que.empty())
    {
        // 가장 먼저 탐색을 시작할 외곽 컨테이너 위치 꺼내기
        auto [x, y] = que.front(); que.pop();
                
        // 상하좌우 탐색
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            // 탐색하려는 위치가 배열 범위를 넘어가는 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // 다음 칸이 탐색 가능한 칸이면 queue에 등록하고 방문 표시
            if (storage[nx][ny] == '.' && !visited[nx][ny])
            {
                que.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
    }
    
    // 제거할 컨테이너를 체크할 vector
    vector<vector<bool>> target(n, vector<bool>(m, false));
    
    // 3. 순회하며 ch와 일치하는 컨테이너 중 접근 가능한 것 체크
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (storage[i][j] != ch) continue;
            
            // 컨테이너가 외곽이면 접근 가능
            bool accessible = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
                
            // 상하좌우 탐색
            for (int d = 0; d < 4; ++d)
            {
                int nx = i + dir[d][0];
                int ny = j + dir[d][1];
            
                // 탐색하려는 위치가 배열 범위를 넘어가는 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
                // 다음 칸이 탐색 가능한 칸이면 접근 가능 표시
                if (storage[nx][ny] == '.' && visited[nx][ny]) accessible = true;
            }
            
            // 접근 가능한 경우 컨테이너 제거
            if (accessible) storage[i][j] = '.';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for (const auto &re : requests)
    {
        // 지게차
        if (re.length() == 1) fork(storage, re[0]);
        // 크레인
        else crane(storage, re[0]);
    }
    
    // 전체에서 컨테이너가 나간 곳(.)의 수 빼고 answer에 더하기
    for (const auto &st : storage) 
        answer += (st.size() - count(st.begin(), st.end(), '.'));
    
    return answer;
}
