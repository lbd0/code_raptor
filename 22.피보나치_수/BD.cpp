#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // F(0) = 0, F(1) = 1
    int pprev = 0, prev = 1;
    
    // F(2)부터 F(n-1)까지 차례로 계산.
    for(int i=2; i<n; ++i)
    {
        if(i%2 == 0)
        {
            pprev = (pprev + prev) %1234567;
        }
        else
        {
            prev = (pprev + prev) %1234567;
        }
    }
    
    // 최종 pprev와 prev를 더하면 F(n) 값이 됨.
    return (pprev+prev) % 1234567;
}
