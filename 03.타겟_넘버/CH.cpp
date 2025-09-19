#include <vector>

using namespace std;

void DFS(const int &index, const int &sum, const vector<int> &numbers, const int &target, int& answer)
{
    if (index == numbers.size())
    {
        if (sum == target)
            ++answer;
        return;
    }
    
    // 현재 숫자를 더한 경우
    DFS(index + 1, sum + numbers[index], numbers, target, answer);
    // 현재 숫자를 뺀 경우
    DFS(index + 1, sum - numbers[index], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, 0, numbers, target, answer);
    
    return answer;
}
