#include <vector>

using namespace std;

long long solution(int n) {
    if (n <= 1) return 1;
    
    // 재귀로 따지면!
    // a = f(n-2), b = f(n-1)
    long long a = 1, b = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        // f(n) = f(n-1) + f(n-2)
        long long temp = (a + b) % 1234567;
        
        // 한 칸 밀어서 다음 계산 준비
        a = b;      // a = f(n-1)
        b = temp;   // b = f(n)
    }
    
    // 마지막 계산된 값 반환
    return b;
}
