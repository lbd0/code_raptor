#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int day;
    
    for(int i = 0; i < progresses.size(); i++){
        int day = ((100 - progresses[i])+ speeds[i] - 1) / speeds[i]; // 필요 일수 계산
        q.push(day);
    }
    
    while (!q.empty()) {
        int cur = q.front(); // 기준이 되는 cur을 비교
        q.pop();
        int cnt = 1;
        
        while (!q.empty() && q.front() <= cur) { // 기준보다 작거나 같으면 함께 배포
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}
