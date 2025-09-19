#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> count(n, 1);
    
    // 여분 체육복 가져온 학생 체육복 수 +1.
    for(const auto& r:reserve)
    {
        count[r-1] += 1;
    }
    
    // 도난 당한 학생 체육복 수 -1.
    for(const auto& l:lost)
    {
        count[l-1] -= 1;
    }
    
    // 체육복 개수 확인 후 없으면 옆사람에게 빌리기.
    for(int i=0; i<n; ++i)
    {
        // 체육복 없으면,
        if(count[i] == 0)
        {
            // 1번 학생이 아니면 앞사람이 2개인지 검사.
            if(i > 0 && count[i-1] >= 2)
            {
                count[i]++;
                count[i-1]--;
                answer++;
            }
            // 마지막 학생이 아니면 뒷사람이 2개인지 검사. (앞사람이 2개가 아니었을 때)
            else if(i < n-1 && count[i+1] >= 2)
            {
                count[i]++;
                count[i+1]--;
                answer++;
            }
            continue;
        }
        // 체육복 있으면 수업 가능.
        answer++;
    }
    
    return answer;
}
