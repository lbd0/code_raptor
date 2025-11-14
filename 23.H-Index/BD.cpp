#include <string>
#include <vector>
#include <map>

using namespace std;

/*
map에 논문 인용 횟수 저장. 근데 h번 이상 인용된 논문이 h편 이상이니까 만약에 3번 인용했으면 map 키가 0부터 3까지 인용 횟수 +1 해줌. => map key가 value보다 작거나 같으면 h편 이상 인용된 것. 근데 최댓값을 구해야 하니까 map 끝까지 돌아서 h-index 값 갱신.
*/

int solution(vector<int> citations) {
    int answer = 0;
    
    map<int, int> mc;
    for(auto& c:citations)
    {
        for(int i=0; i<=c; ++i)
        {
            mc[i]++;
        }
    }
    
    for(auto& m:mc)
    {
        if(m.first <= m.second)
        {
            answer = m.first;
        }
    }
    
    return answer;
}
