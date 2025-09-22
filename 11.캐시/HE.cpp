// 풀이 참고했습니다
#include <iostream> 
#include <string> 
#include <vector> 
#include <list> 
#include <unordered_set> 
#include <algorithm> 


using namespace std; 

int solution(int cacheSize, vector<string> cities) {

    int cost = 0; // 실행시간
    int sz = cities.size(); 
    list<string> cache; 
    unordered_set<string> st; 

    for (int i = 0; i < sz; i++) {

        string city = cities[i]; 
      //대문자 변환 -> 대소문자 구분X
        transform(city.begin(), city.end(), city.begin(), ::toupper); 

        if (cacheSize == 0) {
            return sz * 5; 
        }

        if (st.count(city) == 1) {
            cost += 1; 
            cache.remove(city); 
            cache.push_back(city); //제거 후 뒤로 이동


        } else if (st.count(city) == 0) { // 캐시 miss
            cost += 5; 
            cache.push_back(city); 
            st.insert(city); 
            if (cache.size() > cacheSize) { // 용량 초과 시 오래된 데이터 제거
                st.erase(cache.front()); 
                cache.pop_front(); 
            }

        }

    }

    return cost; 

}
