// 시간 초과 이슈로 결국 풀이 참고....
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    
    queue<pair<int, int>> q; // 연산 값, 횟수
    q.push(pair(x, 0));
    set<int> s; // 중복 체크 set
  
    s.insert(x);
    
    while(!q.empty())
    {
        int current = q.front().first; // 현재 값
        int step = q.front().second; // 연산 횟수
        
        q.pop();
        
        if(current == y) return step; // y에 도달했다면 횟수 반환
        
        int value[3] = {current + n, current * 2, current * 3};
        
        for(int i : value)
        {
            if(i <= y && s.find(i) == s.end()) // 중복이 아닐 시
            {
                q.push(pair(i, step + 1));
                s.insert(i);
            }
        }
    }
    
    return -1;
}
