#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
insert VS emplace / push_back VS emplace_back
insert / push_back : 객체를 밖에서 생성하여 복사 / 이동 -> 느림.
emplace / emplace_back : 객체를 안에서 바로 생성 -> 빠름.

컨테이너에 저장할 객체가 생성 비용이 클 경우 (pair, string, 사용자 정의 클래스 등) => emplace / emplace_back

BUT!!
emplace는 전달된 인자가 정확히 생성자의 형태와 맞아야 함
잘못 전달하면 원치 않는 생성자가 호출될 수 있음
디버깅 어려울 때 있음
=> 단순한 자료형: push_back / insert
*/

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 키가 중복 가능한 맵.
    multimap<string, pair<int, int>> songs;
    
    // 장르별 재생 횟수 저장할 맵.
    unordered_map<string, int> genres_cnt;
    
    for(int i=0; i<genres.size(); ++i)
    {
        // 장르 이름을 키로, (고유번호, 재생횟수)를 값으로 multimap에 저장.
        songs.emplace(genres[i], pair<int,int>(i, plays[i]));
        
        // 장르별 총 재생 횟수 저장.
        genres_cnt[genres[i]] += plays[i];
    }
    
    // 장르별 재생 횟수 내림차순 정렬
    vector<pair<string, int>> g_c(genres_cnt.begin(), genres_cnt.end());
    
    sort(g_c.begin(), g_c.end(),
         [](auto& a, auto& b) { return a.second > b.second; });
    
    // 속한 노래가 많이 재생된 장르부터 수록.
    for(auto& g:g_c)
    {
        // 중복된 키의 값들 모두 가져오기.
        auto range = songs.equal_range(g.first);
        
        vector<pair<int, int>> s_c;
        
        for(auto it=range.first; it!=range.second; ++it)
        {
            s_c.emplace_back(it->second.first, it->second.second);
        }
        // 가져온 노래들 내림차순 정렬.
        sort(s_c.begin(), s_c.end(), cmp);
        
        // 1개면 하나만 선택, 2개 이상이면 2개 선택.
        answer.push_back(s_c[0].first);
        if(s_c.size() > 1) answer.push_back(s_c[1].first);
    }
    
    
    return answer;
}
