#include <string>
#include <vector>

using namespace std;

// int로 바꿔주는 함수
int Date(const string &str)
{
    return stoi(str.substr(0, 4)) * 12 * 28 + stoi(str.substr(5, 2)) * 28 + stoi(str.substr(8, 2));
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // 오늘을 int로 변환
    int tDate = Date(today);
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        // 수집 일자를 int로 변환
        int pDate = Date(privacies[i]);
        int term = 0;
        
        for (const string &t : terms)
        {
            // 약관 종류에 따라 유효기간 term에 저장
            if (t.front() == privacies[i].back())
                term = stoi(t.substr(2)) * 28;
        }
        
        // 수집 일자와 유효기간을 더함
        pDate += term;
        
        // 만약 유효기간이 지났으면 파기
        if (pDate <= tDate) answer.push_back(i + 1);
    }
    
    return answer;
}
