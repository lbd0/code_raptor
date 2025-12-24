using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    // 놀이기구를 count번 탈 때 필요한 금액
    for (int i = 1; i <= count; ++i) answer += i * price;

    // 필요한 금액이 가진 금액보다 크면 차액 반환
    return (answer <= money) ? 0 : answer - money;
}
