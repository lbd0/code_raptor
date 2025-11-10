#include <string>
#include <vector>

using namespace std;

/*
피보나치 수열 이용.
재귀는 시간 초과 ㅎ.
반복문 사용함.
재귀는 f(n) = f(n-1) + f(n-2) 로 n부터 1까지 내려가면서 계산하고,
반복문은 f(1) + f(2) + f(3) ... + f(n) 이렇게 차례대로 계산하는 방식.
+ 값이 커지니까 1234567로 나눈 나머지로 값 저장.
동적계획법으로도 할 수 있대요.
*/

long long solution(int n) {
    
    long long pprev = 0, prev = 1;
    
    // f(1)부터 f(n-1)까지 계산
    for(int i=1; i < n; ++i)
    {
        // i가 홀수면 (n-2)값에 저장.
        if(i%2 != 0)
        {
            pprev = (pprev + prev) % 1234567;
        }
        // 짝수면 (n-1)값에 저장.
        else
        {
            prev = (pprev + prev) % 1234567;
        }
    }
    
    // f(n) 계산.
    return (pprev + prev) % 1234567;
}
