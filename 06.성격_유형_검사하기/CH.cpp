#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    // 정답을 저장할 answer
    string answer = "";
    // 지표를 저장할 allPersonals와 점수판 역할의 personal
    map<char, int> personal;
    vector<string> allPersonals = {"RT", "CF", "JM", "AN"};
    
    // 성격 유형
    personal['R'] = 0;
    personal['T'] = 0;
    personal['C'] = 0;
    personal['F'] = 0;
    personal['J'] = 0;
    personal['M'] = 0;
    personal['A'] = 0;
    personal['N'] = 0;
    
    // 문제 수만큼 반복
    for (int i = 0; i < survey.size(); ++i)
    {
        char c;
        // 비동의
        if (choices[i] <= 3)
        {
            c = (survey[i])[0];
            personal[c] += (4 - choices[i]);
        }
        // 동의
        else if (choices[i] >= 5)
        {
            c = (survey[i])[1];
            personal[c] += (choices[i] - 4);
        }
        // 모름
        else continue;
    }
    
    // 결과 도출
    for (const string &s : allPersonals)
    {           
        answer += (personal[s[0]] > personal[s[1]]) ? s[0] :    // 지표별 성격 유형 비교
                  (personal[s[0]] < personal[s[1]]) ? s[1] :
                  (s[0] < s[1]) ? s[0] : s[1];                  // 같은 경우 사전순 비교
    }
    
    return answer;
}
