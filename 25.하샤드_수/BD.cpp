#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    // 자릿수 합 계산에 이용할 변수와 저장할 변수.
    int h = x, cnt = 0;
    
    // 자릿수 합 저장.
    while(h > 0)
    {
        cnt += h % 10;
        h /= 10;
    }
    
    // 하샤드 수인지 검사.
    if(x%cnt != 0) answer = false;
    
    return answer;
}
