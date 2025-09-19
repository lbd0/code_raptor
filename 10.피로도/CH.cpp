#include <vector>
#include <algorithm>

int solution(int k, std::vector<std::vector<int>> dungeons) {
    int answer = -1;
    
    // 사전 정렬
    std::sort(dungeons.begin(), dungeons.end());
    
    // next_permutation을 통해 완전탐색
    do {
        int cnt = 0;    // 던전 탐색 횟수
        int hp = k;     // 피로도 복사
        
        for (const auto &d : dungeons)
        {
            // 최소 필요 피로도보다 적으면 다음으로
            if (d[0] > hp) continue;
            
            // 피로도 감소 및 던전 탐색 횟수 증가
            hp -= d[1];
            ++cnt;
        }
        
        // 최대 던전 탐색 횟수 저장
        answer = (answer >= cnt) ? answer : cnt;
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}
