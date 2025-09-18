#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    int j;

    for (i = 2; i <= n; i++) {
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                break; // 나눠지면 소수가 아니므로 break;
            }
        }
        if (j * j > i) { //끝까지 나눠지지 않으면 카운트
            answer++;
        }
    }

    return answer;
}
