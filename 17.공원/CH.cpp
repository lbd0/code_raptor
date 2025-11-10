#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    // 내림차순 정렬
    sort(mats.rbegin(), mats.rend());

    // 가로와 세로 길이
    int row = park.size();
    int col = park[0].size();
    
    // 큰 수부터 비교
    for (const int& m : mats)
    {
        // 만약 가로, 세로가 m보다 작으면 넘어가기
        if (m > row || m > col) continue;
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                // 만약 i, j부터 m개를 비교할 수 없다면 넘어가기
                if (row < i + m || col < j + m) break;
                
                // 돗자리 깔 수 있는지 저장
                bool canMat = true;
                
                // 깔 수 있다면 가로, 세로 m x m만큼 비었는지 확인
                if (park[i][j] == "-1")
                {                    
                    for (int x = i; x < i + m; ++x)
                    {
                        for (int y = j; y < j + m; ++y)
                        {
                            if (park[x][y] != "-1")
                            {
                                canMat = false;
                                break;
                            }
                        }
                        if (!canMat) break;
                    }
                    // m x m만큼 비었다면 m 크기의 돗자리 설치 가능
                    if (canMat) return m;
                }
            }
        }
    }
    
    // 설치 불가능하면 -1 반환
    return -1;
}
