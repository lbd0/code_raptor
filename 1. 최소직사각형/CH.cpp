// 1번 방법
#include <vector>
#include <algorithm>

int solution(std::vector<std::vector<int>> sizes) {

    // 작은 수가 0번 자리에 오도록 정렬
    for(std::vector<int> &v : sizes)
        std::sort(v.begin(), v.end());

    // 변수 2개 생성
    int min = sizes[0][0], max = sizes[0][1];

    for (int i = 0; i <= 1; ++i)
    {
        for (std::vector<int> &v : sizes)
        {
            // 작은 수 중에 가장 큰 수 저장
            if (i == 0)
                (v[i] > min) ? min = v[i] : min;
            // 큰 수 중에 가장 큰 수 저장
            else if (i == 1)
                (v[i] > max) ? max = v[i] : max;
        }
    }

    return (min * max);
}

// 2번 방법
#include <vector>

int solution(std::vector<std::vector<int>> sizes)
{
    // 변수 2개 생성
    int min = 0, max = 0;
    
    for (std::vector<int> &v : sizes)
    {
        // v[0]과 v[1] 중 작은 수를 찾아 min과 비교하여 큰 수를 min에 저장
        min = std::max(min, std::min(v[0], v[1]));
        // v[0]과 v[1] 중 큰 수를 찾아 max와 비교하여 큰 수를 max에 저장
        max = std::max(max, std::max(v[0], v[1]));
    }

    return (min * max);
}
