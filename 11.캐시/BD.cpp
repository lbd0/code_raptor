#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

// value 기준 오름차순 정렬.
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
    
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    unordered_map<string, int> cache;
    
    // 최근에 사용할 수록 값↑.
    int cnt = 0;
    
    for(auto& city:cities)
    {
        // 대소문자 구분하지 않으니, 모두 대문자로 변환.
        transform(city.begin(), city.end(), city.begin(),
                   [](unsigned char c){ return toupper(c); });
        
        // cache hit,
        if(cache.find(city) != cache.end())
        {
            // 실행 시간 1.
            answer += 1;
        }
        // cache miss,
        else
        {
            // 실행 시간 5.
            answer += 5;
        }
        
        // 맵에 최근에 사용했는지 확인하는 수 저장.
        cache[city] = ++cnt;
        
        // 캐시 크기보다 크면, 오래전에 사용한 캐시 삭제.
        if(cache.size() > cacheSize)
        {
            // value 기준 오름차순 정렬.
            vector<pair<string, int>> temp(cache.begin(), cache.end());
            sort(temp.begin(), temp.end(), cmp);
            
            // 정렬된 벡터의 0번째 요소가 가장 오래전에 사용한 캐시.
            if(!temp.empty())
                cache.erase(temp[0].first);
        }
    }
    
    return answer;
}
