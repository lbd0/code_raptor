#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // 옷 종류에 따른 갯수 저장할 맵.
    map<string, int> type;
    
    // 옷 종류에 따라 갯수 맵에 저장.
    for(const auto& cloth:clothes)
    {
        type[cloth[1]]++;
    }
    
    // 상의가 2개면 상의1, 상의2, 상의 안 고름으로 경우의 수가 3이니까 개수+1을 곱합.
    // 해당 종류의 옷을 고를 경우의 수.
    for(const auto& t:type)
    {
        answer *= t.second+1;
    }
    
    // 최소 한 개의 의상은 입어야 하므로 아무것도 안 입는 경우 뺴줌.
    return answer-1;
}
