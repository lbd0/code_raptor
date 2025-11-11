#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq; // 우선순위 큐
    
    for (int w : works) pq.push(w); // 큐에 작업량 push

    while (n > 0) {
        int cw = pq.top();
        if (cw == 0) break; // 다 했으면 넘어가기
        pq.pop();
        cw--; // 작업량 감소
        pq.push(cw);
        n--; // 1시간 감소
    }

    while (!pq.empty()) { // 야근 지수 계산
        int tir = pq.top();
        pq.pop();
        answer += tir * tir;
    }
    
    return answer;
}
