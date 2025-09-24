#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // 작업 완료에 걸리는 시간을 큐에 저장
    for (int i = 0; i < speeds.size(); ++i)
    {
        int due = (100 - progresses[i]) / speeds[i];
        
        if ((100 - progresses[i]) % speeds[i] != 0) ++due;
        
        q.push(due);
    }
    
    int cnt = 0, date = q.front();
    
    while (!q.empty())
    {
        // 이전 작업보다 걸리는 일수가 적거나 같으면
        // 같이 끝낼 수 있으니 pop
        if (date >= q.front())
        {
            q.pop();
            ++cnt;
        }
        // 다음 작업이 더 오래 걸리는 경우
        else
        {
            answer.push_back(cnt);
            cnt = 0;
            date = q.front();
        }
    }
    
    // 만약 남은 작업이 있었던 경우를 위해
    if (cnt > 0) answer.push_back(cnt);
    
    return answer;
}
