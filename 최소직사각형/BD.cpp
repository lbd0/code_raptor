// 명함의 긴 쪽을 가로로, 짧은 쪽을 세로로.
// 가로에서 최대값, 세로에서 최대값 계산.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> width;
    vector<int> height;
    
    // 명함의 가로 세로를 나누는 과정 (긴 쪽을 가로, 짧은 쪽을 세로)
    for(int i=0; i<sizes.size(); ++i)
    {
        width.push_back((sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1]));
        height.push_back((sizes[i][0] > sizes[i][1] ? sizes[i][1] : sizes[i][0]));
    }
    
    // 내림차순 정렬
    sort(width.rbegin(), width.rend());
    sort(height.rbegin(), height.rend());
    
    answer = width[0] * height[0];
    
    return answer;
}
