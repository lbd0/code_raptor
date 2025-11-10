#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    while (n > 0) { //n이 0일 때 중지
        if (n % 2 != 0) { //남은 거리가 홀수일 때 점프
            n -= 1;
            ans++;
        }
        else n /= 2; //남은 거리가 짝수일 때 순간이동
    }
    
    return ans;
}

