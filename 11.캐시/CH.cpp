#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 순서를 저장하기 위한 list와 캐시 역할을 할 unordered_map
list<string> cacheList;
unordered_map<string, list<string>::iterator> cache;

string toLower(const string& str)
{
    string lower = str;
    // 대소문자 무시하기 때문에 소문자 변환
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    
    return lower;
}

int GET(const string &key)
{
    string cKey = toLower(key);
    
    // 캐시에 없다면 -1 반환
    if (cache.find(cKey) == cache.end()) return -1;
    
    // 사용된 key의 순서를 가장 앞으로 변경
    auto it = cache[cKey];
    string value = *it;
    
    cacheList.erase(it);
    cacheList.push_front(value);
    cache[cKey] = cacheList.begin();
    
    return 1;
}

void PUT(const string& key, const int& cacheSize)
{
    string cKey = toLower(key);
    
    // 앞에 삽입
    cacheList.push_front(cKey);
    cache[cKey] = cacheList.begin();
    
    // 용량 초과 시, 가장 오래된 것(뒤쪽) 제거
    if (cacheList.size() > cacheSize)
    {
        string del = cacheList.back();
        cache.erase(del);
        cacheList.pop_back();
    }
}

int solution(int cacheSize, vector<string> cities) 
{
    // 캐시를 사용하지 않는 경우
    if (cacheSize == 0) return cities.size() * 5;
    
    // 전역 변수 초기화
    cache.clear();
    cacheList.clear();
    
    // 총 실행 시간
    int answer = 0;
    
    for (const string& city : cities)
    {
        if (GET(city) == -1)        // 캐시에 없는 경우
        {
            PUT(city, cacheSize);   // 캐시에 넣기
            answer += 5;            // cache miss
        }
        else answer += 1;           // cache hit
    }
    
    return answer;
}
