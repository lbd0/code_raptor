#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    // 선분 세 개를 정렬
    sort(sides.begin(), sides.end());
    
    // 가장 긴 변의 길이가 다른 두 변의 길이의 합보다 작으면 1, 크면 2
    return (sides[0] + sides[1] > sides[2]) ? 1 : 2;
}
