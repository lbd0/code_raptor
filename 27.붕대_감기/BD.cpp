#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    // 현재 체력.
    int answer = health;
    
    // 연속 성공 시간.
    int cnt = 0;
    
    // attacks 인덱스.
    int a_idx = 0;
    
    // 시전 시간, 초당 회복량, 추가 회복량.
    int time = bandage[0], recover = bandage[1], bonus = bandage[2];
    
    for(int i=1; i<=attacks[attacks.size()-1][0]; ++i)
    {
        // 공격 당하면,
        if(a_idx < attacks.size() && attacks[a_idx][0] == i)
        {
            // 연속 성공 0.
            cnt = 0;
            // 데미지 적용.
            answer -= attacks[a_idx][1];
            // 다음 공격.
            a_idx++;
        }
        else 
        {
            // 연속 성공 +1.
            cnt++;
            
            // 초당 회복량 적용. 근데 최대 체력보다 낮을 때만 적용.
            answer = min(answer+recover, health);
              
            // 시전 시간과 연속 성공 시간 같으면 추가 회복량 적용.
            if(cnt == time)
            {
                // 연속 성공 시간 초기화.
                cnt = 0;
                
                // 최대 체력보다 낮을 때만 추가 회복량 적용.
                answer = min(answer+bonus, health);
            }
        }
        
        // 현재 체력이 0 이하면 사망 처리.
        if(answer <= 0) return -1;
    }
    
    return answer;
}
