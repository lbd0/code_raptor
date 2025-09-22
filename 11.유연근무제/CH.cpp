#include <vector>

using namespace std;

// 10분을 더해주는 함수
void schdeuling(int &schedule)
{
    schedule += 10;
    
    // 60분이 넘었을 경우 -60 +100을 해줌
    if (schedule % 100 >= 60) schedule += 40;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    // 직원 수만큼 반복
    for (int i = 0; i < schedules.size(); ++i)
    {
        // 출근 희망 시각과 요일 변수
        int schedule = schedules[i];
        int curday = startday;
        
        // 10분 더하기
        schdeuling(schedule);
        
        // 일주일만 반복
        for(int j = 0; j < 7; ++j)
        {
            // 요일이 8이 되면 다시 1로 설정해줌
            if (curday >= 8) curday %= 7;
            
            // 주말이 아니면
            if (curday != 6 && curday != 7)
            {
                // 출근 희망 시각보다 출근 시간이 크면(늦으면)
                if (timelogs[i][j] > schedule)
                {
                    curday = 0;
                    break;
                }
            }
            
            // 요일 넘어가기
            ++curday;
        }
        
        // 요일이 0이 아니면(늦은 적 없으면) 상품
        if (curday) ++answer;
    }
    
    return answer;
}
