#include <string>
#include <stack>

int solution(std::string s)
{
    std::stack<char> st;
    
    // 스택이 비어있지 않고, top이 c와 같으면 pop, 아니면 push
    for (const auto &c : s)
        (!st.empty() && st.top() == c) ? st.pop() : st.push(c);
    
    // 스택이 비었다면 성공, 아니면 실패
    return st.empty() ? 1 : 0;
}
