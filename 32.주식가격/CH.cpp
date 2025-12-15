#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> indexs;          // 인덱스를 저장할 변수
    
    for (int i = 0; i < n; ++i) {
        // 가격이 떨어졌을 때
        while (!indexs.empty() && prices[indexs.top()] > prices[i]) {
            int idx = indexs.top(); indexs.pop();
            answer[idx] = i - idx;
        }
        
        // 아직 떨어지지 않았을 경우
        indexs.push(i);
    }
    
    // 떨어지지 않은 경우 처리
    while (!indexs.empty()) {
        int idx = indexs.top(); indexs.pop();
        answer[idx] = (n - 1) - idx;
    }
    
    return answer;
}
