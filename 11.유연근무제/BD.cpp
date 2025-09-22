#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0; i<schedules.size(); ++i)
    {
        // 지각 체크.
        bool late = false;
        // 요일 체크. 반복문에서 바로 ++ 해줄거라 -1 해줌.
        int day = startday-1;
        
        // 출근 인정 시각.
        int s_hour = schedules[i] / 100;
        int s_min = schedules[i] % 100 + 10;
        
        // 분이 60분 이상하면 시간 +1, 분은 -60.
        if(s_min >= 60)
        {
            s_hour += 1;
            s_min -= 60;
        }
        
        for(const auto& time:timelogs[i])
        {
            day++;
            
            // 토요일 패스.
            if(day == 6) continue;
            // 일요일 패스 및 요일 0으로 변경.
            if(day == 7)
            {
                day = 0;
                continue;
            }
            
            // 출근 시각.
            int t_hour = time / 100;
            int t_min = time % 100;
            
            // 출근 인정 시각과 출근 시각 비교.
            if(s_hour < t_hour) 
            {
                late = true;
                break;
            }
            
            if(s_hour == t_hour)
            {
                if(s_min < t_min) 
                {
                    late = true;
                    break;
                }
            }
        }
        // 지각 안 했으면 선물++.
        if(!late) answer++;
    }
    return answer;
}
