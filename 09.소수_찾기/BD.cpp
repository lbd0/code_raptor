#include <vector>
#include <cmath>
using namespace std;

// 에라토스테네스의 체 라는 알고리즘이라네요,,
// https://cocoon1787.tistory.com/88 여기 참고했구요.
// 소수의 배수는 소수가 아니니까 소수의 배수를 찾아서 모조리 지우는 그런 알고리즘이래요.

int solution(int n) {
    int answer = 0;
    
    // 0부터 n까지의 벡터를 모두 true로 저장.
    vector<bool> is_sosu(n+1, true);
    
    // 루트(n)보다 작은 수의 배수만 지워도 다 지워짐.
    for(int i=2; i<=sqrt(n); ++i)
    {
        // 이미 false 이면 패쓰 소수가 아닌 것.
        if(!is_sosu[i]) continue;
        
        // 소수이면, 배수들을 모조리 false로 변경.
        for(int j=i*2; j<=n; j+=i)
        {
            is_sosu[j] = false;
        }
    }
    
    // 벡터에서 true 찾아서 더함.
    for(const auto& s:is_sosu)
    {
        if(s) answer++;
    }
    
    // 0과 1은 소수가 아닌데 true로 저장해놨기 때문에 -2 해줌.
    return answer-2;
}
