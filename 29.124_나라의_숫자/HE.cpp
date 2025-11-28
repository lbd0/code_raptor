// 124 법칙: 3으로 나누고 나머지가  0이면 4, 몫에 -1 반복...................
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while (n > 0) {
        int a = n % 3; // 3으로 나눔
        
        if (a == 0) {
            answer += '4'; // 나머지 0이면 4
            n = n / 3 - 1; // 몫에 -1
        }
        else {
            answer += to_string(a); // 나머지 그대로
            n /= 3;
        }
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}
