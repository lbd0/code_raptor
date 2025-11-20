#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    (s.size() % 2 != 0) ? answer += s[s.size() / 2]: answer += s.substr((s.size() / 2 - 1), 2);
    
    return answer;
}
