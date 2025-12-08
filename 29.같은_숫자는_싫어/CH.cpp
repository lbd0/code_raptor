#include <vector>
#include <queue>

std::vector<int> solution(std::vector<int> arr) 
{
    std::queue<int> que;
    std::vector<int> answer;
    
    // arr의 원소를 하나씩 꺼냄
    for (const auto& a : arr)
    {
        // arr의 첫 원소를 큐에 넣기
        if (que.empty()) que.push(arr[0]);
        
        // 스택의 최상위 데이터가 a가 아니면 스택에 넣기
        if (que.back() != a) que.push(a);
    }
    
    while (!que.empty())
    {
        // 스택의 최상위 데이터를 벡터에 넣기
        answer.push_back(que.front());
        que.pop();
    }
    
    return answer;
}
