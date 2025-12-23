// 풀이 참고
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    for (int a = 1; a <= n; a++) { // 모든 수 탐색
        for (int b = a + 1; b <= n; b++) {
            for (int c = b + 1; c <= n; c++) {
                for (int d = c + 1; d <= n; d++) {
                    for (int e = d + 1; e <= n; e++) {

                        vector<int> code = {a, b, c, d, e}; // 임시 비밀코드
                        bool can = true;

                        for (int i = 0; i < q.size(); i++) { 
                            int cnt = 0;

                            for (int x : code) { // 코드에 q 매칭
                                for (int y : q[i]) {
                                    if (x == y) cnt++;
                                }
                            }

                            if (cnt != ans[i]) { // 맞은 개수가 ans와 다르면 false
                                can = false;
                                break;
                            }
                        }

                        if (can) answer++;
                    }
                }
            }
        }
    }
    return answer;
}
