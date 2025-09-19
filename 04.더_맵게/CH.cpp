#include <queue>
#include <vector>

int solution(std::vector<int> scoville, int K) {
    // 정답을 저장할 answer
    int answer = 0;
    // 최소 힙 우선순위 큐 사용
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    
    // 우선순위 큐에 스코빌 지수 넣기
    for (const int &i : scoville)
    {
        pq.push(i);
    }
    
    // 우선순위 큐는 내림차순으로 자동 정렬
    // 비어있지 않거나 K보다 작은 수가 있는 경우
    while (!pq.empty() && pq.top() < K)
    {
        // 음식이 하나 남은 경우
        if (pq.size() < 2) return -1;
        
        // 가장 작은 수 2개 저장
        int first = pq.top();   pq.pop();
        int second = pq.top();  pq.pop();
        
        // 계산 후 우선순위 큐에 넣기
        pq.push(first + second * 2);
        
        // 정답 1 증가
        ++answer;
    }
    
    return answer;
}
