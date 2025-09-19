#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 전체 학생의 체육복 조사를 위한 벡터
    vector<int> students(n, 1);
    
    // 잃어버린 학생, 여벌이 있는 학생 체크
    for (const auto &l : lost)  --students[l - 1];
    for (const auto &r : reserve) ++students[r - 1];
    
    for (int i = 0; i < n; ++i)
    {
        // 체육복이 1개 이상이면 answer 증가
        if (students[i] >= 1)
        {
            ++answer;
            continue;
        }
        
        // 첫번째 학생은 뒤, 마지막 학생은 앞에만 조사
        if (i > 0 && students[i - 1] == 2)              --students[i - 1];
        else if (i < (n - 1) && students[i + 1] == 2)   --students[i + 1];
        else continue;
        
        ++students[i];
        ++answer;
    }
    
    return answer;
}
