#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    // a와 b가 같다면 a 반환
    if (a == b) return a;
    
    // b가 더 작다면 둘을 바꿔줌
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // a부터 b까지 더하기
    for (int i = a; i <= b; ++i) answer += i;
    
    return answer;
}
