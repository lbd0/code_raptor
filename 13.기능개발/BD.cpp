#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 기능 별 완성까지 며칠 걸리는지 저장할 변수.
    queue<double> release;
    
    // 배포되는 기능 저장할 변수.
    int cnt = 0;
    
    // 완성까지 며칠 걸리는 지 계산 및 큐에 저장.
    for(int i=0; i<progresses.size(); ++i)
    {
        double days = ceil((100.0 - progresses[i]) / speeds[i]);
        release.push(days);
    }
    
    // 큐 맨 처음 값 저장.
    double rd = release.front();
    release.pop();
    cnt++;
    
    // 큐가 비워질 때까지 반복.
    while(!release.empty())
    {
        // 완성까지 걸리는 시간이 크면 다음 배포 때 배포.
        if(release.front() > rd)
        {
            // 이번 배포에 배포할 기능 수 저장.
            answer.push_back(cnt);
            
            // 다음 배포가 며칠 뒤인지 저장.
            rd = release.front();
            release.pop();
            cnt = 1;
            continue;
        }
        
        // 작으면, 이번 배포 때 배포.
        release.pop();
        cnt++;
    }
    
    // 큐가 비워진 후 cnt가 남아있으면, 마지막 배포.
    if(cnt != 0) answer.push_back(cnt);
    
    return answer;
}
