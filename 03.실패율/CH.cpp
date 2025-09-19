#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 실패율, 순서를 저장할 vector
    vector<double> faults(N, 0.f);
    vector<double> indexs(N, 0.f);
    
    // 정렬
    sort(stages.begin(), stages.end());
    
    // 전체 플레이어 수
    int players = stages.size();
    
    for (int i = 1; i <= N; ++i)
    {
        if (players == 0) break;
        
        // 개수를 구하기 위해 i의 시작 인덱스와 끝 인덱스를 구해 빼주기
        auto lower = lower_bound(stages.begin(), stages.end(), i);
        auto upper = upper_bound(stages.begin(), stages.end(), i);
        
        faults[i - 1] =  static_cast<double>(upper - lower) / players;
        players -= (upper - lower);
    }
    
    indexs = faults;
    // 내림차순 정렬
    sort(faults.begin(), faults.end(), greater<double>());
    
    for (const double & f : faults)
    {
        for (int i = 0; i < indexs.size(); ++i)
        {
            if (f != indexs[i]) continue;
            
            // faults와 indexs 값이 같으면 indexs의 인덱스를 저장
            answer.push_back(i + 1);
            indexs[i] = -1;
            break;
        }
    }
    
    return answer;
}
