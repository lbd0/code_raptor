#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(true)
    {
        // 라운드 시작할 때, ++.
        ++answer;
        
        // 다음 라운드 참가 번호 : 짝수 = 현재 번호/2, 홀수 = 현재 번호/2 + 1
        a = a%2==0 ? a/2 : ceil(a/2)+1;
        b = b%2==0 ? b/2 : ceil(b/2)+1;
        
        // a와 b가 붙었으면, 다음 라운드 참가 번호가 같음!
        if(a==b) break;
    }

    return answer;
}
