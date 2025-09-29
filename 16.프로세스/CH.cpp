#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // index, priority 저장할 queue
    queue<pair<int, int>> que;
    
    // que에 index, priority 저장
    for (int i = 0; i < priorities.size(); ++i) que.push({i, priorities[i]}); 
    
    while (!que.empty())
    {
        // 대기중인 프로세스 하나 꺼냄
        auto num = que.front(); que.pop();
        // 나머지 대기중인 프로세스를 temp에 복사
        queue<pair<int, int>> temp = que;
        
        // 우선순위가 높은 경우 true
        bool check = false;
    
        while (!temp.empty())
        {
            // 꺼낸 프로세스보다 우선순위가 높은 프로세스가 있는 경우
            if (num.second < temp.front().second)
            {
                check = true;
                break;
            }
            
            temp.pop();
        }
        
        // 우선순위가 높은 프로세스가 있으면 다시 que에 넣기
        if (check) que.push(num);
        else
        {
            // 실행
            ++answer;
            // 찾던 프로세스이면 종료
            if (num.first == location) break;
        }
    }
    
    return answer;
}
