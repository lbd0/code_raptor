#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int p = 0; // 칠한 구역

    for (int s : section) {
        if (s > p) { // 현재 구역보다 칠할 구역이 더 뒤에 있을 때
            answer++; // 칠한 횟수 +1
            p = s + m - 1;
        }
    }
    
    return answer;
}
