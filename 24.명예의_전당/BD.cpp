#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    // 우선 순위 큐 최소힙으로 만들기 => 작은 수가 top 자리로.
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // score 벡터 돌면서 우선순위큐에 저장.
    for(int i=0; i<score.size(); ++i)
    {
        if(i < k) pq.push(score[i]);
        else
        {
            if(pq.top() < score[i])
            {
                pq.pop();
                pq.push(score[i]);
            }
        }
        // 우선순위큐 (명예의 전당)에서 최하위 점수 저장.
        answer.push_back(pq.top());
    }
    
    return answer;
}
