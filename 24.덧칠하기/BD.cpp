#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int end = 0;
    
    // 왼쪽부터 칠하면 최소로 칠 할 수 있음.
    for(auto& s:section)
    {
        if(end < s)
        {
            // 한 번 칠했을 때 페인트가 칠해진 끝 번호 저장.
            end = s + m - 1;
            answer++;
        }
        else continue;
    }
    
    return answer;
}
