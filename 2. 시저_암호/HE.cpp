#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    char c;
    n = n % 26; // n값이 클 때 방지
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            c = ' '; // 공백 처리
        }
        else if (s[i] >= 'a' && s[i] <= 'z') { //소문자
            c = (s[i] - 'a' + n) % 26 + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') { //대문자
            c = (s[i] - 'A' + n) % 26 + 'A';
        }
        answer += c;
    }
    return answer;
}
