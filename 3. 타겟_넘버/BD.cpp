// 질문하기 참고해서 풀었습니다..
#include <string>
#include <vector>

using namespace std;

int dfs(int idx, int sum, vector<int> numbers, int target)
{
    // 벡터 끝까지 돌았으면 타겟 넘버와 같은지 확인.
    if(idx == numbers.size())
    {
        return target == sum ? 1:0; // 같으면 1, 다르면 0 반환.
    }
    
    // 현재 숫자를 + 했을 때, - 했을 때 결과 합쳐서 반환.
    return dfs(idx + 1, sum + numbers[idx], numbers, target) + dfs(idx + 1, sum - numbers[idx], numbers, target);
    
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(0, 0, numbers, target);
    
    return answer;
}
