#include <string>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> st;
    
    while (n > 0) {
        // 나머지가 3이면 4로 바꾸기
        // 나머지가 0이면 4로 바꾸고 몫을 1 빼기
        if (n % 3 == 0 || n % 3 == 3) st.push(4);
        else st.push(n % 3);
        
        if (n % 3 == 0) (n /= 3)--;
        else n /= 3;
    }
    
    while (!st.empty()) {
        answer += to_string(st.top());
        st.pop();
    }
    
    return answer;
}
