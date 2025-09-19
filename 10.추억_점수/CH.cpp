#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    // 이름, 점수를 세트로 저장할 map
    unordered_map<string, int> number;
    
    // map 초기화
    for (int i = 0; i < name.size(); ++i)
        number[name[i]] = yearning[i];
    
    for (const vector<string> &p : photo)
    {
        // 합산할 변수
        int cnt = 0;
        
        // 맵에서 이름 별 점수를 찾아 합산
        for (int i = 0; i < p.size(); ++i)
            cnt += number[p[i]];
        
        answer.push_back(cnt);
    }
    
    return answer;
}
