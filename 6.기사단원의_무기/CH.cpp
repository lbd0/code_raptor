#include <cmath>

int solution(int number, int limit, int power) {
    // 철의 무게를 저장할 answer
    int answer = 0;
    
    // 1~number까지 반복
    for (int i = 1; i <= number; ++i)
    {
        // 약수의 개수를 저장할 divisors
        int divisors = 0;
        
        // 1~i의 제곱끈까지 반복
        for (int j = 1; j <= std::sqrt(i); ++j)
        {
            // i를 j로 나눌 수 있다면
            if (i % j == 0)
            {
                // 약수의 개수를 증가
                ++divisors;
                
                // 만약 i를 약수로 나눈 값이 j와 같지 않다면 약수 개수 증가 
                if (j != i / j) ++divisors;
            }
        }
        
        // 약수의 개수가 limit보다 크면 power, 작으면 약수의 개수를 더함
        answer += (limit < divisors) ? power : divisors;
    }
    
    return answer;
}
