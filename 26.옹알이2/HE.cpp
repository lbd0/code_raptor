#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};

    for (string s : babbling) {
        string prev = ""; // 이전 단어
        bool pr = true; // 발음 가능 여부
        int i = 0;

        while (i < s.size()) {
            bool match = false;

            for (string w : words) {
                if (i + w.size() <= s.size() && s.substr(i, w.size()) == w && w != prev) {
                    prev = w;
                    i += w.size();
                    match = true;
                    break;
                }
            }
            if (!match) { // 발음 불가
                pr = false;
                break;
            }
        }
        if (pr) answer++; // 발음 가능 카운트
    }
    return answer;
}
