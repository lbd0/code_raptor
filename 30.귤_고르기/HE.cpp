#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> tannum(10000001, 0); // 종류별 개수 저장
    
    for (int n : tangerine) tannum[n]++;

    sort(tannum.begin(), tannum.end(), greater<int>()); // 내림차순 정렬

    for (auto p : tannum) { // 가장 많은 종류부터 k에서 감소
        if (k <= 0) break;
        k -= p;
        answer++; // 종류 카운트
    }
    
    return answer;
}
