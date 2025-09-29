#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(const string s) { // 올바른 괼호 문자열 체크
    int cnt = 0;
    
    for(char c : s) {
        if(c == '(') cnt++;
        else if( --cnt < 0)  // ')' 만나면 카운트 감소
            return false; // 카운트가 음수면 false
    }
    return cnt == 0;
}

string solution(string p) {
    if(p.empty()) return "";  // 빈 문자열이면 반환

    string u, v;
    int cnt = 0;

    for(int i = 0; i < p.size(); i++) {
        cnt += (p[i] == '(') ? 1 : -1; // '('면 +1, ')'면 -1
        if(cnt == 0) { 
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }

    if(check(u)) return u + solution(v); // u가 올바른 괄호 문자열이면 v 재귀

    string answer = "(" + solution(v) + ")";
    for(char c : u.substr(1, u.size()-2)) // 뒤집기
        answer += (c == '(') ? ')' : '(';
    return answer;
}
