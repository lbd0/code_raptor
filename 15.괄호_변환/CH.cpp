#include <string>

using namespace std;

string solution(string p) {
    string answer = "";
    
    // 빈 문자열이면 빈 문자열 반환
    if (p.empty()) return answer;
    
    // 균형잡인 괄호 저장할 u와 나머지 저장할 v
    string u = "", v = "";
    
    // 짝 확인을 위한 cnt
    int cnt = 0;
    
    do {
        // p의 가장 앞의 문자를 가져오고, (이면 -1, )이면 +1 후 지우기
        u += p[0];
        p[0] == '(' ? --cnt : ++cnt;
        p.erase(0, 1);
    } while (cnt != 0);

    // 나머지를 v에 넣기
    v = p;
    
    // 올바른 괄호 문자열인지 확인하기 위한 변수
    bool isCorrect = true;
    
    for (const auto& s : u)
    {
        // )이면 -1
        s == ')' ? --cnt : ++cnt;
        
        // -1이면 짝이 맞지 않음
        if (cnt < 0) 
        {
            isCorrect = false;
            break;
        }
    }
    
    // 짝이 맞다면 문자열 v를 1단계부터 다시 수행한 후 u에 붙여 반환
    if (isCorrect)  return answer = u + solution(v);
    
    // ( + v를 1단계부터 수행 + )
    answer = "(" + solution(v) + ")";
    
    // 처음과 마지막 문자 지우기
    u.erase(0, 1);  u.erase(u.size() - 1, 1);
    
    // 괄호 방향 뒤집기
    for (auto& s : u)    s = (s == '(') ? ')' : '(';
    
    // answer에 u를 붙인 후 반환
    return answer += u;
}
