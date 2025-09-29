#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // for문 사용, 맨 앞 삭제를 위해 deque 사용함.
    // queue는 for문 사용 X.
    deque<pair<char, int>> q;
    
    // 초기 대기큐 저장하기 위한 변수.
    char temp = 'A';
    // location에 해당하는 프로세스 저장하기 위한 변수.
    char p;
    
    // 초기 대기 큐 저장 및 location 프로세스 저장.
    for(int i=0; i<priorities.size(); ++i)
    {
        if(location == i) p = temp;
        q.push_back({temp++, priorities[i]});
    }
    
    // 문제에서 주어진 의사 코드에 따라 구현.
    while(true)
    {
        // 실행할 수 있는지 검사하는 변수.
        bool is_run = true;
        
        // 실행 대기 큐에서 프로세스 하나 꺼냄.
        pair<char, int> process = q.front();
        
        // 우선 순위 높은게 있는지 확인.
        for(const auto& pair:q)
        {
            // 높은게 있으면 실행 X.
            if(process.second < pair.second) 
            {
                is_run = false;
                q.push_back(process);
                break;
            }
        }
        
        q.pop_front();
        
        // 우선 순위 높은거 없으면 프로세스 실행.
        if(is_run) 
        {
            answer++;
            // 실행하는 프로세스가 location의 프로세스이면 반복문 종료.
            if(process.first == p) break;
        }
    }
    
    return answer;
}
