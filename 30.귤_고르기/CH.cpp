#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> um;
    
    // 귤 크기 별 개수 세기
    for (const auto& t : tangerine) {
        ++um[t];
    }
    
    // 귤 개수에 따라 크기 정렬하기
    vector<pair<int, int>> vec(um.begin(), um.end()); 
    
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });
    
    // 최솟값 구하기
    for (const auto &v : vec) {
        k -= v.second;
        ++answer;
        
        if (k <= 0) break;
    }
    
    return answer;
}
