#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(auto& c:s)
    {
        // 공백은 그냥 공백으로 넣어주기
        if(c == ' ') answer += " ";
        else
        {
            // char로 작성 시 오버플로우 발생하는 테스트 케이스 있음.
            unsigned char temp = c + n;
            
            // 주어진 알파벳이 대문자인 경우 A-Z에서만 밀 수 있음
            if('A' <= c && c <= 'Z')
            {
                if(temp > 'Z')
                {
                    temp = (temp-1) - 'Z' + 'A';
                }
            }
            else
            {
                if(temp > 'z')
                {
                    temp = (temp-1) - 'z' + 'a';
                }
            }
            
            answer += temp;
        }
    }
    
    if(answer.empty()) return "YES";
    return answer;
}
