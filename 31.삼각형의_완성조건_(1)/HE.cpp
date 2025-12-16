#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    sort(sides.begin(), sides.end()); // 정렬

    if (sides[2] < sides[0] + sides[1]) answer = 1; // 가장 긴 변의 길이가 다른 두 변의 길이의 합보다 작은지 검사
    else answer = 2;
        
    return answer;
}
