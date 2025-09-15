#include <string>
#include <vector>
using namespace std;

// 약수 개수 구하는 함수.
int divisor(int a)
{
    // 1, n은 무조건 이므로 2개부터 시작.
    int count = 2;
    
    // a가 0보다 작으면 없음.
    if(a < 0) return 0;
    // a가 1이면 약수 1개.
    else if(a == 1) return 1;
    
    // a가 2이상일 때, a/2까지 => a/2보다 큰 수는 약수가 될 수 없음.
    for(int i=2; i<=a/2; ++i)
    {
        if(a%i == 0) count++;
    }
    
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1; i<=number; ++i)
    {
        int cnt = divisor(i);
        
        // 약수 개수가 제한 수치보다 크면,
        if(cnt > limit)
        {
            // 공격력이 power인 무기 구매.
            answer += power;
        }
        else
        {
            // 제한 수치보다 작거나 같으면, 공격력이 약수 개수인 무기 구매
            answer += cnt;
        }
    }
    
    return answer;
}
