#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0, idx = 0;
    unordered_map<int, int> count;
    
    for(auto& t:tangerine)
    {
        count[t]++;
    }
    
    // map의 value 기준 내림차순 정렬.
    vector<pair<int, int>> v_count(count.begin(), count.end());
    
    sort(v_count.begin(), v_count.end(), [](pair<int,int> a, pair<int, int> b)      {
        return a.second > b.second;
    });
    
    while(cnt < k)
    {   
        ++answer;
        cnt += v_count[idx++].second;
    }
    
    return answer;
}
