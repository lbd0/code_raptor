#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 스택에 담고, 스택 비워지면 모두 지워진 것.
// 스택 사용하지 않으면 효율성에서 실패.

int solution(string s)
{
    stack<char> s_stack;
    
    for(const auto& a:s)
    {
        // 스택이 비어있지 않을 때, 맨 위에 있는 글자와 같으면,
        if(!s_stack.empty() && s_stack.top() == a)
        {
            // 스택에서 빼기.
            s_stack.pop();
        }
        // 다르면,
        else 
            // 스택에 넣기.
            s_stack.push(a);
    }

    // 스택이 비어있으면, 1 아니면 0.
    return s_stack.empty() ? 1:0;
}
