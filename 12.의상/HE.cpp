#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> closet;
    int answer = 1; // 최소 하나는 입음

    for (auto c : clothes) { // 옷 종류, 개수 저장
        string type = c[1];
        closet[type]++;
    }
    
    for (auto p : closet) { // 경우의 수 계산
        answer *= (p.second + 1); // 안 입는 경우를 위해 1을 더함
    }

    return answer - 1; // 다 벗었을 경우(1) 제외
}
