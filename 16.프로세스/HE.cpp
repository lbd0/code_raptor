//풀이참고
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    queue<pair<int, int> > q; // priorities의 인덱스, 우선순위 저장

    for(int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]}); // 삽입
        pq.push(priorities[i]); // 우선순위순으로 삽입
    }

    int count = 1;
    while(true) {
        pair<int, int> temp = q.front();
        q.pop();

        if(temp.second != pq.top()) // 우선순위가 더 높은 프로세스가 있다면
            q.push(temp); // 다시 넣기
        else
            if(temp.first == location) { // location 프로세스 실행순서에 answer에 count값 삽입
                answer = count;
                break;
            }
            else {
                count++;
                pq.pop();
            }
    }
    return answer;
}
