#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = 0;

    for (char c : s) {
        if (c == ' ') { // 공백일 경우
            answer += ' ';
            i = 0;
        }
        else {
            if (i % 2 == 0) answer += toupper(c); // 대문자로
            else answer += tolower(c); // 소문자로
            i++;
        }
    }
    return answer;
}
