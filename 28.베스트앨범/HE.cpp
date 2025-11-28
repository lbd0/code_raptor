// 풀이 참고

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> total; // 장르별 재생수
    map<string, vector<pair<int,int>>> songs; // 장르별 재생수, 고유번호

    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({ plays[i], i });
    }

    vector<pair<string, int>> order(total.begin(), total.end());
    sort(order.begin(), order.end(), [](auto& a, auto& b) { return a.second > b.second; }); // 재생수 기준으로 내림차순 정렬

    vector<int> answer;

    for (auto& g : order) {
        auto& v = songs[g.first];

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
                 if (a.first == b.first) return a.second < b.second;
                 return a.first > b.first;
             });

        answer.push_back(v[0].second);
        if (v.size() > 1) answer.push_back(v[1].second);
    }

    return answer;
}
