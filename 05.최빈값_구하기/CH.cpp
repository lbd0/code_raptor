#include <vector>
#include <map>

int solution(std::vector<int> array) {
    // 정답을 저장할 answer
    int answer = -1;
    // 최빈값을 구하기 위한 map
    std::map<int, int> map;
    
    // array에서 나온 값을 Key, 빈도수를 Value로 저장
    for (const int &a : array)
    {
        ++map[a];
    }
    
    // 현재 answer의 빈도수가 m의 빈도수보다 적으면 m의 숫자를 저장
    // 현재 answer의 빈도수와 m의 빈도수가 같으면 -1 저장
    // 현재 answer의 빈도수가 m의 빈도수보다 많으면 answer 유지
    for (const auto &m : map)
    {
        answer = (map[answer] < m.second) ? m.first : (map[answer] == m.second) ? -1 : answer;
    }
    
    return answer;
}
