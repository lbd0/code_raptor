#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// GPT한테 힌트 얻음.
// 2D Prefix Sum (2차원 누적합) : 영역의 합을 빠르게 구하는 방법.

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
   
    // 돗자리 크기 큰 순서대로 정렬하면 빠르게 구할 수 있음.
    sort(mats.begin(), mats.end(), greater<int>());
    
    // park 벡터를 0,1로 저장할 벡터. 사람 있 0 없 1.
    vector<vector<int>> park2;
    
    // prefix[i][j] = (0,0)부터 (i,j)까지의 합. 미리 저장해 놓고 아래에서 꺼내서 사용.
    vector<vector<int>> prefix(park.size()+1, vector<int>(park[0].size()+1, 0));
    
    // park벡터를 park2벡터로 변환.
    for(auto& pa:park)
    {
        vector<int> temp;
        for(auto& p:pa)
        {
            if(p.compare("-1") == 0) temp.push_back(1);
            else temp.push_back(0);
        }
        park2.push_back(temp);
    }
    
    // prefix 벡터 저장.
    for(int i=1; i<prefix.size(); ++i)
    {
        for(int j=1; j<prefix[0].size(); ++j)
        {
            // 2D Prefix Sum 구하는 공식.
            prefix[i][j] = park2[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    // 정사각형 영역 합 구해서 돗자리 깔 수 있는지 확인.
    for(const auto& m:mats)
    {
        int sum = 0;
        for(int i=1; i+m-1 < prefix.size(); ++i)
        {
            for(int j=1; j+m-1 < prefix[0].size(); ++j)
            {
                // 사각형 영역 합 구하는 공식.
                sum = prefix[i+m-1][j+m-1] - prefix[i-1][j+m-1] - prefix[i+m-1][j-1] + prefix[i-1][j-1];
                
                if(m*m == sum) return m;
            }
        }
    }
    
    return answer;
}
