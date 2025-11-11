#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for (const auto& w : works) pq.push(w);
    
    while (n > 0 && !pq.empty())
    {
        int i = pq.top();   pq.pop();
        
        if (i == 0) break;
        
        pq.push(--i);
        --n;
    }
    
    while (!pq.empty())
    {
        int i = pq.top(); pq.pop();
        answer += i * i;
    }
    
    return answer;
}
