#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열 검사하는 함수.
bool check(string str)
{
    stack<char> s;
    
    for(auto& c:str)
    {
        if(c == ')' || c == ']' || c == '}') 
        {
            if(s.empty()) return false;
            
            char temp = s.top();
            s.pop();
            
            if(temp == '(' && c != ')') return false;
            if(temp == '[' && c != ']') return false;
            if(temp == '{' && c != '}') return false;
        }

        else
        {
            s.push(c);
        }
    }
    
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); ++i)
    {
        // 문자열 왼쪽으로 회전.
        string temp = s.substr(i) + s.substr(0, i);
        
        if(check(temp)) answer++;
    }
    
    return answer;
}
