#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
스택에 인덱스 저장해놓고, 스택에서 뽑아오면서 뒷 큰수 찾음.
못 찾으면 -1.
*/

vector<int> solution(vector<int> numbers) {
    // 못 찾으면 -1이니까 -1로 초기화. 인덱스에 직접 접근하여 값 수정할 것이므로 초기화 필요.
    vector<int> answer(numbers.size(), -1);
    
    stack<int> st;
    
    for(int i=0; i<numbers.size(); ++i)
    {
        // 뒷 큰수 있으면 answer에 저장.
        while(!st.empty() && numbers[st.top()] < numbers[i]){
            answer[st.top()] = numbers[i];
            st.pop();
        }
        // 스택에 인덱스 저장.
        st.push(i);
    }
    
    return answer;
}
