#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> h1 = {1,2,3,4,5};
    vector<int> h2 = {2,1,2,3,2,4,2,5};
    vector<int> h3 = {3,3,1,1,2,2,4,4,5,5};
    int c1 = 0, c2 = 0, c3 = 0; // 정답 체크

    for (int i = 0; i < answers.size(); i++) { // 답안 반복 비교
        if (answers[i] == h1[i % 5]) c1++;
        if (answers[i] == h2[i % 8]) c2++;
        if (answers[i] == h3[i % 10]) c3++;
    }

    int score = max({c1, c2, c3}); // 가장 큰 수 계산

  // 동점일 경우 고려
    if (c1 == score) answer.push_back(1);
    if (c2 == score) answer.push_back(2);
    if (c3 == score) answer.push_back(3);
  
    return answer;
}
