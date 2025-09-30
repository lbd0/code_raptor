#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    
    vector<vector<int>> emp(park.size(), vector<int>(park[0].size(), 0)); //빈자리 계산하기 위한 벡터
    int maxsize = 0; //최대 정사각형 크기
    
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == "-1") {// 빈 자리 기준으로 정사각형 계산 (빈 자리: 정사각형의 오른쪽 아래)
                if (i == 0 || j == 0) {
                    emp[i][j] = 1; // 처음이 빈 자리일 경우 따로 1처리
                } else {
                    emp[i][j] = min({emp[i-1][j], emp[i][j-1], emp[i-1][j-1]}) + 1; // 주변 자리 체크하면서 정사각형 확장
                }
                maxsize = max(maxsize, emp[i][j]); //최대 정사각형 크기
            }
        }
    }
    
    sort(mats.begin(), mats.end()); //정렬
    int answer = -1;
    
    for (int mat : mats) {
        if (mat <= maxsize) answer = mat; // mats에서 고르기
    }
    
    return answer;
}
