#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto& com:commands)
    {
        // 자른 배열을 임시로 저장할 벡터
        vector<int> temp;
        
        // i번째부터 j번째까지 temp 벡터에 저장
        for(int i=com[0]-1; i<com[1]; ++i)
        {
            temp.push_back(array[i]);
        }
        
        // temp 벡터 정렬
        sort(temp.begin(), temp.end());
        
        // k번째 숫자 찾기
        answer.push_back(temp[com[2]-1]);
    }
    
    return answer;
}
