#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 우선 순위 큐 활용. 스코빌 지수가 낮은 순으로 정렬하여 계산.
    priority_queue<int, vector<int>, greater<int>> scov;
    
    // 우선 순위 큐에 스코빌 지수 저장.
    for(auto& s:scoville)
    {
        scov.push(s);    
    }
    
    // 음식 섞기
    while(true)
    {
        // 우선 순위 큐 가장 앞에 있는 수가 K 이상이면 모든 스코빌 지수가 K 이상임.
        if(scov.top() >= K) return answer;
        
        // 우선 순위 큐의 크기가 1개 이하이면 모든 음식의 스코빌 지수가 K 이상으로 만들 수 없는 경우임.
        if(scov.size() <= 1) return -1;
        
        // 첫 번째로 맵지 않은 음식의 스코빌 지수 저장하고 우선 순위 큐에서 제거.
        int first = scov.top();
        scov.pop();
        
        // 두 번째로 맵지 않은 음식의 스코빌 지수 저장하고 우선 순위 큐에서 제거.
        int second = scov.top();
        scov.pop();
        
        // 새로운 음식의 스코빌 지수 우선 순위 큐에 저장.
        scov.push(first + second * 2);
        
        // 섞은 횟수 저장.
        answer++;
    }
    
}
