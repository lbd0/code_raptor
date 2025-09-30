#include <iostream>
using namespace std;

// n을 2로 나눈 나머지 값이 점프한 칸, 몫을 또 2로 나눠서 계산.
// 0에서 1로 무조건 점프.
// 5 = 1 + jump(2)->0 + jump(1)->1 => 2.
int jump(int n)
{
    if(n <= 1) return 1;
    
    return n%2 + jump(n/2);
}

int solution(int n)
{
    int ans = 0;

    ans += jump(n);
    
    return ans;
}
