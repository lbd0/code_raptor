#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // 옷의 조합을 저장할 answer, 옷의 수를 셀 unordered_map
    int answer = 1;
    unordered_map<string, int> fashion;
    
    // 종류별 옷의 수
    for (const auto &c : clothes) ++fashion[c[1]];
    
    // 각 종류별로 착용했을 경우의 수(f.second) + 착용 안 했을 경우의 수(1)
    for (const auto &f : fashion) answer *= (f.second + 1);
    
    // 아무것도 안 입을 경우(-1)
    return --answer;
}
