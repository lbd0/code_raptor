#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stack<int> scores;
    int i = 0;

    while (i < dartResult.length()) {
        int num = 0;

        // 숫자 조립 (10 처리)
        if (isdigit(dartResult[i])) {
            // 10일 수 있으므로
            if (dartResult[i] == '1' && i + 1 < dartResult.length() && dartResult[i + 1] == '0') 
            {
                num = 10;
                i += 2;
            } 
            else {
                num = dartResult[i] - '0';
                ++i;
            }
        }

        // 보너스
        if (dartResult[i] == 'S') 
        {
            num = pow(num, 1);
        } 
        else if (dartResult[i] == 'D') 
        {
            num = pow(num, 2);
        } 
        else if (dartResult[i] == 'T') 
        {
            num = pow(num, 3);
        }
        
        ++i;

        scores.push(num);

        // 옵션 처리
        if (i < dartResult.length()) 
        {
            if (dartResult[i] == '*') 
            {
                // 현재 점수 * 2
                int current = scores.top(); scores.pop();
                current *= 2;

                // 이전 점수도 있으면 * 2
                if (!scores.empty()) 
                {
                    int prev = scores.top(); 
                    scores.pop();
                    prev *= 2;
                    scores.push(prev);
                }

                scores.push(current);
                ++i;
            } 
            else if (dartResult[i] == '#') 
            {
                // 현재 점수 * -1
                int current = scores.top(); 
                scores.pop();
                current *= -1;
                scores.push(current);
                ++i;
            }
        }
    }

    // 총합
    int answer = 0;
    
    while (!scores.empty()) 
    {
        answer += scores.top();
        scores.pop();
    }

    return answer;
}
