#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for(int i=0; i<absolutes.size(); ++i)
    {
        // 음수면 -1 곱해줌.
        if(!signs[i])
        {
            absolutes[i] *= -1;
        }
        
        // absolutes 돌면서 더함.
        answer += absolutes[i];
    }
    
    
    return answer;
}
