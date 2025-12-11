#include <vector>
#include <algorithm>

int solution(int k, int m, std::vector<int> score) {
    int sum = 0;
    // 내림차순으로 정렬
    sort(score.rbegin(), score.rend());
    // 사과를 m개씩 담기
    for (int i = m - 1; i < score.size(); i += m) sum += score[i] * m;
    return sum;
}
