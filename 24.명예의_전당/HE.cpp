#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> f; // 명예의 전당 벡터

    for (int i = 0; i < score.size(); i++) {
        f.push_back(score[i]);
        sort(f.begin(), f.end()); // 오름차순 정렬

        if (f.size() > k) { // k번을 넘어갈 경우 가장 작은 수 삭제
            f.erase(f.begin());
        }

        answer.push_back(f[0]); // 최하위 점수 발표
    }
    return answer;
}
