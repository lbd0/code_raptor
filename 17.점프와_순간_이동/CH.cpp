int solution(int n)
{
    int ans = 0;

    while (n > 0)
    {
        // 홀수면 점프, 짝수면 순간이동
        if (n % 2 != 0) 
        {
            --n;
            ++ans;
        }
        else n /= 2;
    }

    return ans;
}
