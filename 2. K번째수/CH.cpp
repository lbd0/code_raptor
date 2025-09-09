#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands) {
    std::vector<int> answer;
    
    // 커맨드에서 하나씩 꺼내기
    for (const std::vector<int> &c : commands)
    {
        // temp에 범위만큼 넣고 정렬한 다음에 answer에 넣기
        std::vector<int> temp(array.begin() + c[0] - 1, array.begin() + c[1]);
        std::sort(temp.begin(), temp.end());
        answer.push_back(temp[c[2] - 1]);
    }
    
    return answer;
}
