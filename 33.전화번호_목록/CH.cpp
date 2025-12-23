#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    // 데이터가 커도 시간 초과되지 않기 위한 해시 사용
    unordered_set<string> us;
    
    // 모든 전화번호를 해시에 저장
    for (const auto& p : phone_book) us.insert(p);
    
    // 각 전화번호의 접두사 검사
    for (const auto& p : phone_book) {
        // 이전 접두사
        string pre = "";
        
        // 자기자신을 비교하지 않기 위해 길이-1까지 검사
        for (int i = 0; i < p.size() - 1; ++i) {
            // 이전 접두사에 넣어주기
            pre += p[i];
            
            // 만약 해시에 있다면 false 반환
            if (us.find(pre) != us.end()) return false;
        }
    }
     
    // 만약 해시에 없다면 true 반환
    return true;
}
