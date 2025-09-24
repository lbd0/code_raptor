int solution(int n, int a, int b)
{
    int answer = 0;  // round
    --a; --b;        // 2로 나눴을 때 몫을 구하기 위해 1 빼기
    
    // 같은 라운드일 때까지
    while (a != b)
    {   
        a /= 2; b /= 2;  // 다음 라운드 진출
        ++answer;        // 라운드 증가
    }

    return answer;
}
