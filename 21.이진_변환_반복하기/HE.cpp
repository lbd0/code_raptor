#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s != "1") {
        string s1; // 0 제거한 string
        string s2; // 이진법 string
        int zero = 0; // 뺀 0의 수
        
        for (char c : s) { // 0을 제외할 때마다 카운트
            if (c != '0') s1 += c;
            else zero++;
        }

        answer[1] += zero; // 0 제외 값 추가
        int len = s1.size(); // s1 길이

        while (len > 0) { // 이진법 변환
            s2 = to_string(len % 2) + s2;
            len /= 2;
        }

        s = s2;
        answer[0]++; // 변환 카운트
    }

    return answer;
}
