#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

/*
작업량이 큰 수부터 처리해야 야근 지수 최소화 할 수 있음 => 우선순위 큐 사용.
*/

long long solution(int n, vector<int> works) {
    long long answer = 0;
        
    // 우선 순위 큐.
    priority_queue<int> pq;
    
    // 우선 순위 큐에 작업량 저장.
    for(auto w:works) pq.push(w);
    
    // n 만큼 작업량 처리.
    while(n > 0)
    {   
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
        n--;
    }
    
    // 야근 지수 계산.
    while(!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();
        
        if(tmp > 0)
            answer += pow(tmp, 2);
    }
    
    return answer;
}
