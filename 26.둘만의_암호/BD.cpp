#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    vector<char> alpha;
    
    // skip에 있는 알파벳 제외한 나머지 저장.
    for(int i=0; i<26; ++i)
    {
        char temp = 'a' + i;
        bool inc = false;
        for(auto sk:skip)
        {
            if(temp == sk)
            {
                inc = true;
                break;
            }
        }
        
        if(!inc) alpha.push_back(temp);
    }
    
    // 저장한 알파벳 벡터에서 index만큼 뒤에 있는 알파벳 찾아서 answer에 추가.
    for(auto ss:s)
    {
        int idx = ((find(alpha.begin(), alpha.end(), ss) - alpha.begin()) + index) % alpha.size();
        
        answer += alpha[idx];
    }
    
    return answer;
}
