#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    // 가능한 네 가지 발음
    vector<string> sounds = { "aya", "ye", "woo", "ma" };
    int answer = 0;
    
    for (const string& b : babbling) {
        string prev = "";           // 이전 발음
        bool isPossible = true;     // 발음할 수 있는 단어인지
        
        for (int i = 0; i < b.length(); ++i) {
            bool matched = false;   // 발음이 일치하는지
            
            for (const auto& s : sounds) {
                // 발음이 일치하고, 이전 발음과 다른 경우
                if (b.substr(i, s.length()) == s && s != prev) {
                    i += s.length() - 1;    // i를 이동
                    matched = true;         // 발음 일치
                    prev = s;               // 이전 발음으로 저장
                    break;
                }
            }
            
            if (!matched) {             // 일치하지 않았다면
                isPossible = false;     // 불가능한 발음
                break;
            }
        }
        
        if (isPossible) ++answer;       // 가능한 발음이면 체크하기
    }
    
    return answer;
}
