#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Music {
    int play;
    int idx;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<Music>> music_by_genres;     // 장르: {재생 수, 고유번호}
    map<string, int> total_play;                    // 장르: 총 재생 수
    
    // 맵에 각각 데이터 저장
    for (int i = 0; i < genres.size(); ++i) {
        music_by_genres[genres[i]].push_back({plays[i], i});
        total_play[genres[i]] += plays[i];
    }
    
    // 총 재생 수를 내림차순으로 정렬
    vector<pair<string, int>> vec(total_play.begin(), total_play.end());
    
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    // 장르 안에서 재생 수에 따라 정렬
    for (auto& m : music_by_genres) {
        auto& v = m.second;
        
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            if (a.play == b.play) return a.idx < b.idx;
            return a.play > b.play;
        });
    }
    
    for (const auto& v : vec) {
        int cnt = 0;
        for (const auto& m : music_by_genres[v.first]) {
            if (++cnt > 2) break;
            answer.push_back(m.idx);
        }
    }
    
    return answer;
}
