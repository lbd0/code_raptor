#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 모든 수의 합을 배열에 넣기
    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    
    // 오름차순으로 정렬
    sort(answer.begin(), answer.end());
    
    // 중복되는 수는 뒤로 보내고, 중복 숫자 시작 위치 반환
    auto last = unique(answer.begin(), answer.end());
    
    // 중복 숫자 지우기
    answer.erase(last, answer.end());
    
    return answer;
}
