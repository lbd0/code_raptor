#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    // 큰 수를 저장할 스택
    stack<int> st;

    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        // 오른쪽의 수가 현재 수보다 작거나 같으면 제거
        while (!st.empty() && st.top() <= numbers[i])  st.pop();
        
        if (!st.empty()) answer[i] = st.top();
        
        st.push(numbers[i]);
    }
    
    return answer;
}
