int solution(int n) {
    int answer = 0;
    // 소수인지 아닌지 판단하는 변수
    int check = 1;
    
    // 2부터 n까지
    for (int i = 2; i <= n; ++i)
    {
        // 제곱근 나눠보기
        for (int j = 2; j * j <= i; ++j)
        {
            // 끝까지 돌기 전 나눠지는 수가 있다면 소수
            if ((check = i % j) == 0) break;
        }
        
        // 소수이면 answer 증가, 아니면 check 다시 true 만들기
        (check) ? ++answer : check = 1;
    }
    
    return answer;
}
