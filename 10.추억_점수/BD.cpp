#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    // 사람 별 그리움 점수 저장할 맵.
    map<string, int> miss;
    
    // 사람 별 그리움 점수 저장. 키 : 사람, 값 : 그리움 점수
    for(int i=0; i<name.size(); ++i)
    {
        miss[name[i]] = yearning[i];
    }
    
    // 사진별 추억 점수 계산.
    for(const auto& ph:photo)
    {
        int count = 0;
        for(const auto& p:ph)
        {
            count += miss[p];
        }
        answer.push_back(count);
    }
    
    return answer;
}
