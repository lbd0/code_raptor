#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a>b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int box = score.size()/m;
    int idx = m;
    
    sort(score.begin(), score.end(), comp);
    
    for(int i=0; i<box; i++)
    {
        answer += score[idx-1] * m;
        idx += m;
    }
    
    return answer;
}
