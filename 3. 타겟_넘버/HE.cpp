//설명 보면서 풀었습니다
#include <string>
#include <vector>

using namespace std;
int answer = 0;

//DFS: 깊이우선탐색. 정점에서 갈 수 있는 점들까지 들어가며 탐색
void DFS(vector<int> numbers, int target, int sum, int index){
    if(index == numbers.size()){ //다 탐색했을 때
        if(sum == target)
            answer++; // 타겟넘버와 같으면 answer 증가
        return; 
    }
    DFS(numbers, target, sum + numbers[index], index + 1);
    DFS(numbers, target, sum - numbers[index], index + 1);
}
int solution(vector<int> numbers, int target){
    DFS(numbers, target, 0, 0);
    return answer;
}
