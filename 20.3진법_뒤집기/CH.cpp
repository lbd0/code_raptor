#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int solution(int n) {
    stack<int> st;
    int answer = 0;
    
    while (n > 0)
    {
        st.push(n % 3);
        n /= 3;
    }
    
    int cnt = 0;
    
    while (!st.empty())
    {
        int nn = st.top();  st.pop();
        
        if (nn != 0) answer += pow(3, cnt) * nn;
        
        ++cnt;
    }
    
    return answer;
}
