#include <string>

using namespace std;

bool solution(string s)
{
    // p와 y의 개수를 비교할 변수
    int cnt = 0;
    
    for (const auto& c : s) {
        // p이면 1 더하고, y면 1 빼기
        if (c == 'p' || c == 'P') ++cnt;
        else if (c == 'y' || c == 'Y') --cnt;
    }
    
    // 개수가 같아 cnt가 0인 경우 true 반환
    return !cnt;
}
