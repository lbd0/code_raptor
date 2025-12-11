#include <string>

using namespace std;

// 월을 일로 환산하는 함수
int increment(int month) {
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    return days[month];
}

// 1월 1일에서 며칠이 흘렀는지 계산하는 함수
int dates(int month) {
    if (month == 1) return 0;
    
    // 이전 달의 일수를 더해주기
    return dates(month - 1) + increment(month - 1);
}

string solution(int a, int b) {
    string answer = "";
    
    // 1월 1일부터 흐른 일수 % 7일
    int day = (dates(a) + b) % 7;
    
    // 1월 1일은 금요일
    string week[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    
    return answer = week[day];
}
