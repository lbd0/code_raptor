#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int digit = 1;
    
    string ternary;
    
    // 뒤집힌 3진법으로 ternary에 저장.
    while(n > 0)
    {
        ternary += to_string(n%3);
        n/=3;
    }
    
    // ternary -> 10진법으로 변환.
    for(int i=ternary.size()-1; i>=0; --i)
    {
        answer += (ternary[i] - '0') * digit;
        digit *= 3;
    }
    
    return answer;
}
