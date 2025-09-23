// 코드가 너무 길어져서 다른 사람 풀이 찾아봤는데 짧고 간결한 코드를 발견했습니다. 저는 왜 이런 생각을 못했을까요?

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    unordered_map<int, int> m; // 숫자와 등장 횟수를 저장하는 맵
    vector<int> answer;
    
    for(int i = 2; i < s.size() - 2; ++i) { // s[2]부터 s[s.size()-2]까지 탐색
        if('0' <= s[i] && s[i] <= '9') {
            m[stoi(s.substr(i))]++; // stoi(s.substr(i)): 현재 숫자
            while('0' <= s[i] && s[i] <= '9') i++; // 숫자가 여러 자리일 경우 i를 숫자 끝까지 이동
        }
    }
    vector<pair<int, int>> mtov(m.begin(), m.end()); // map은 정렬이 안되기 때문에 vector로 바꾼 뒤 정렬
    sort(mtov.begin(), mtov.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 등장 횟수 기준 내림차순 정렬
    });
    for(int i = 0; i < mtov.size(); ++i)
      answer.push_back(mtov[i].first);
    return answer;
}
