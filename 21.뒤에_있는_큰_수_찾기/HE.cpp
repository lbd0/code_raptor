// 그냥 하면 시간초과 떠서 스택 사용 (풀이 참고)

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); // 기본값 -1 지정
    stack<int> num; // 인덱스를 저장할 스택

    for (int i = numbers.size() - 1; i >= 0; i--) {
        while (!num.empty() && numbers[i] >= numbers[num.top()]) { 
            num.pop(); // 현재 인덱스보다 작거나 같은 값 제외해서 비교
        }

        if (!num.empty()) { // 뒷 큰수
            answer[i] = numbers[num.top()];
        }
        
        num.push(i); // 현재 인덱스 추가
    }

    return answer;
}
