#include <string>
#include <vector>
#include <stack>
using namespace std;

// 올바른 괄호 문자열인지 검사하는 함수.
// 스택에 '(' 저장하고, ')' 이면 pop, ')'인데 스택이 비어있거나, 문자열 다 돌았는데 스택이 비어있지 않으면 올바른 괄호 문자열이 아닌 것.
bool rightPar(const string& u)
{
    // '(' 담을 스택.
    stack<char> s;
    
    for(const auto& a:u)
    {
        if(a == '(')
        {
            s.push(a);
        }
        else
        {
            if(s.empty()) return false;
            
            s.pop();
        }
    }
    
    if(s.empty()) return true;
    
    return false;
}

string solution(string p) {
    string answer = "";
    
    // 입력이 빈 문자열인 경우, 빈 문자열 반환.
    if(p.empty()) return "";
    
    // 균형잡힌 괄호 문자열로 분리.
    // '(', ')' 각각의 개수 세어서 비교해도 되지만, 스택 사용함.
    string u="", v="";
    
    stack<char> s;
    
    for(int i=0; i<p.length(); ++i)
    {
        // 스택이 비었으면 균형잡힌 괄호 문자열 완성된 것.
        if(i != 0 && s.empty()) 
        {
            v = p.substr(i);
            break;
        }
        
        // '('와 ')'의 개수가 같으면 되므로, 스택에 저장되어 있는 거랑 같으면 스택에 저장.
        if(i == 0 || s.top() == p[i])
        {
            s.push(p[i]);
        }
        // 다르면 스택에서 꺼내기.
        else
        {
            s.pop();
        }
        
        // 문자열 u로 저장.
        u += p[i];
    }
    
    // u가 올바른 괄호 문자열 이라면
    if(rightPar(u))
    {
        // v에 대해 1단계부터 다시 수행.
        answer += u + solution(v);
    }
    // u가 올바른 괄호 문자열이 아니면,
    else
    {
        // '(' 로 시작하는 문자열.
        string temp = "(";
        
        // v에 대해 재귀 수행 후 문자열 이어붙임.
        temp += solution(v);
        
        // ')' 추가.
        temp += ")";
        
        // u의 첫 번째, 마지막 문자 제외, 나머지 괄호 방향 뒤집어서 붙임.
        for(int i=1; i<u.length()-1; ++i)
        {
            temp += (u[i]=='(') ? ')':'(';
        }
        
        // 반환.
        answer += temp;
    }
    
    return answer;
}
