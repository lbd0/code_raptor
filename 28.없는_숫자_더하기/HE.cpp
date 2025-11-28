#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45; // 0부터 9까지의 합 45
    
    for (int n : numbers) // 45에서 numbers 원소 빼기
        answer -= n;

    return answer;
}
