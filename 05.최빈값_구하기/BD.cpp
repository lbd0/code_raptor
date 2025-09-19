#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자가 나온 횟수 기준 내림차순 정렬하기 위한 함수.
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(vector<int> array) {
    int answer = 0;
    
    // (숫자, 나온 횟수) 저장하기 위한 벡터.
    vector<pair<int, int>> sort_count;
    
    for(auto& a:array)
    {
        if(sort_count.size() > 0)
        {
            for(int i=0; i<sort_count.size(); ++i)
            {
                // 벡터에 숫자가 있으면 횟수++.
                if(sort_count[i].first == a)
                {
                    sort_count[i].second++;
                    break;
                }
                
                // 숫자가 없으면 벡터에 넣어줌.
                else if(i==sort_count.size()-1)
                {
                    sort_count.push_back(pair<int, int>(a, 1));
                    break;
                }
            }
        }
        // 벡터가 비어있으면 넣어줌.
        else
            sort_count.push_back(pair<int, int>(a, 1));
    }
    
    // 숫자가 나온 횟수 기준으로 내림차순 정렬.
    sort(sort_count.begin(), sort_count.end(), cmp);
    
    // 최빈값이 없으면 -1, 있으면 최빈값 반환.
    return sort_count[0].second == sort_count[1].second ? -1:sort_count[0].first;
}
