#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 실패율 기준으로 정렬.
bool cmp(vector<float> x, vector<float> y)
{
    // 실패율이 같으면 스테이지 번호가 낮은 거부터 정렬.
    if(x[1] == y[1])
        return x[0] < y[0];
    
    // 실패율이 높은 순으로 정렬.
    return x[1] > y[1];
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 스테이지 번호와 실패율 저장하는 2차원 벡터 (스테이지 번호, 실패율)로 저장. 행: 스테이지 개수, 열: 2.
    vector<vector<float>> fail_rate(N, vector<float>(2));
    
    // 플레이어 수 저장 변수.
    float players = stages.size();
    
    // 실패율 계산해서 fail_rate 벡터에 저장.
    for(int i=1; i<=N; ++i)
    {
        int fail_players = 0;
        
        for(auto& s:stages)
        {
            if(i==s) fail_players++;
        }
        
        // (스테이지 번호, 실패율) 형태로 저장.
        fail_rate[i-1].assign({(float)i, players == 0 ? 0:fail_players / players});
        
        players -= fail_players;
        
    }
    
    // 실패율 순 내림차순 정렬.
    sort(fail_rate.begin(), fail_rate.end(), cmp);
    
    // 정렬된 스테이지 번호 저장.
    for(auto& fail:fail_rate)
    {
        answer.push_back(fail[0]);
    }
    
    return answer;
}
