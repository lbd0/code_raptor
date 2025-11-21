#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // 초기 등수 저장.
    vector<string> answer = players;
    
    // 플레이어 별 등수 저장.
    unordered_map<string, int> rank;
    
    // 맵에 플레이어 별 등수 저장.
    for(int i=0; i<players.size(); ++i)
    {
        rank[players[i]] = i;
    }
    
    // 순위 변경.
    for(auto& c:callings)
    {
        // answer배열의 인덱스 찾기.
        int idx = rank[c];
        int f_idx = idx - 1;
        
        // 맵에 사용할 키 찾기 (앞사람 이름).
        string front = answer[f_idx];
        
        // 앞사람이랑 순위 바꾸기.
        swap(answer[idx], answer[f_idx]);
        
        // 맵 갱신.
        rank[front] = idx;
        rank[c] = f_idx;
    }
    
    return answer;
}
