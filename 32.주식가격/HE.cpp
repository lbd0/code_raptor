#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            answer[i]++;
            if (prices[j] < prices[i]) {
                break; // 가격이 떨어지면 종료
            }
        }
    }
    
    return answer;
}
