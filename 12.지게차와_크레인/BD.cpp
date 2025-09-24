#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

// CH 참고했어요~

void fork(vector<string>& storage, const char& alpha)
{
    int n = storage.size(); // 세로 길이.
    int m = storage[0].size();  // 가로 길이.
    
    // 방문 여부 저장할 벡터.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // BFS에 사용할 큐.
    queue<pair<int, int>> q;

    // 외곽 큐에 저장.
    // 왼쪽, 오른쪽 외곽.
    for(int i=0; i<n; ++i)
    {
        for(int j : {0, m-1})
        {
            if(storage[i][j] == ' ' && !visited[i][j])
            {
                q.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    
    // 위, 아래 외곽.
    for(int j=0; j<m; ++j)
    {
        for(int i:{0, n-1})
        {
            if(storage[i][j] == ' ' && !visited[i][j])
            {
                q.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    
    // 상하좌우 방향 저장한 이차원배열.
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // 큐 비워질 때까지 '외부'에 해당하는 곳 visited 벡터에 표시.
    while(!q.empty())
    {
        // 큐에서 좌표 가져옴.
        auto [x, y] = q.front(); 
        q.pop();
        
        // 해당 좌표의 상하좌우 검사.
        for(int i=0; i<4; ++i)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            // 범위 벗어나면 패스.
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // '외부'에 해당하면 큐에 추가하고, visited 표시.
            if(storage[nx][ny] == ' ' && !visited[nx][ny])
            {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
    }
    
    // 컨테이너 제거.
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(storage[i][j] != alpha) continue;
            
            // 외곽이면 컨테이너 제거하고 넘어가.
            if(i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                storage[i][j] = ' ';
                continue;
            }
            
            // '외부'와 연결 여부.
            bool possible = false;
            
            // 상하좌우 검사하여 '외부'와 연결되었는지 확인.
            for(int k=0; k<4; ++k)
            {
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(storage[nx][ny] == ' ' && visited[nx][ny]) possible = true;
            }
            
            // '외부'와 연결되었으면 컨테이너 제거.
            if(possible) storage[i][j] = ' ';
        } 
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for(const auto& r:requests)
    {
        // 요청 알파벳이 하나면 지게차, 두개면 크레인
        switch(r.length())
        {
            case 1:
                fork(storage, r[0]);
                break;
                
            case 2:
                // 크레인
                for(auto& s:storage)
                {
                    replace(s.begin(), s.end(), r[0], ' ');
                }
                break;
        }
    }
    
    // 전체 크기 - ' '의 수 = 남은 컨테이너 수
    for(const auto& s:storage)
    {
        answer += (s.size() - count(s.begin(), s.end(), ' '));
    }
    
    
    return answer;
}
