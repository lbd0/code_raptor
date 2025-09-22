#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); i++) { // 시간 변환
            int hour = schedules[i] / 100;
            int minute = (schedules[i] % 100) + 10;
        
            if (minute >= 60) {
                hour += 1;
                minute -= 60;
            }
        int time = hour * 100 + minute;
        int work = 0; //출근 횟수
        
        for (int j = 0; j < 7; j++) { 
            int today = (startday + j - 1) % 7 + 1;
            
            if (today == 6 || today == 7) // 주말 처리
                continue;
            
            if (timelogs[i][j] <= time) {
                work++;
            }
        }
        
        if (work == 5) { // 상품 대상
            answer++;
        }
    }
    return answer;
}
