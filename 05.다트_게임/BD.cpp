#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    // 기회 3번이니까 숫자는 3개 나올 수 있음. 숫자를 저장할 벡터.
    vector<int> scores(3);
    
    // scores의 index.
    int idx = -1;
    
    for(int i=0; i<dartResult.size(); ++i)
    {
        // dartResult가 숫자이면 벡터에 넣어줌.
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            // dartResult가 0인데 그 전에 나온 dartResult가 1이면 10이 됨.
            if(i!=0 && dartResult[i] == '0' && dartResult[i-1] == '1')
            {
                scores[idx] = 10;
            }
            else
            {
                // 숫자 scores 벡터에 저장.
                scores[++idx] = dartResult[i] - '0';
            }
        }
        
        // 숫자 보너스 옵션 순이므로 scores[idx]가 보너스 혹은 옵션 앞에 있는 숫자임.
        // S는 변화 없으므로 제외.
        // D이면 2제곱. 
        if(dartResult[i] == 'D')
        {
            scores[idx] = pow(scores[idx], 2);
        }
        // T이면 3제곱.
        else if(dartResult[i] == 'T')
        {
            scores[idx] = pow(scores[idx], 3);
        }
        // *이면 2배.
        else if(dartResult[i] == '*')
        {
            if(idx != 0)
            {
                scores[idx-1] *= 2;
            }
            scores[idx] *= 2;
        }
        // #이면 -1배.
        else if(dartResult[i] == '#')
        {
            scores[idx] *= -1;
        }
    }
    
    for(auto& s:scores)
    {
        answer += s;
    }
    
    return answer;
}
