#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int timeToMin(string t) { //시간 변환
    int h = stoi(t.substr(0 , 2));
    int m = stoi(t.substr(3 , 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    int answer = 0;
    
    for (auto bt : book_time) {
        int start = timeToMin(bt[0]); // 시작 시간
        int end = timeToMin(bt[1]) + 10; // 종료 시간 + 청소 시간
        times.push_back({start, end});
    }
    
    sort(times.begin(), times.end()); //정렬
    
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 큐

    for (auto &t : times) {
        if (!pq.empty() && pq.top() <= t.first) {
            pq.pop(); // 이전 퇴실 시간이 다음 입실 시간 전이라면 퇴실 시간 제거 (새로운 방 사용하지 않음)
        }
        pq.push(t.second); // 현재 손님 퇴실 시간 추가
    }

    answer = pq.size(); // 원소 수 = 객실 수
    return answer;
}
