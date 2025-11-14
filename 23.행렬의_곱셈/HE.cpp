#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0)); // 크기: arr1 행 크기 × arr2 열 크기, 0 초기화 // 지정 안하면 오류

    for (int i = 0; i < arr1.size(); i++)
        for (int j = 0; j < arr1[0].size(); j++)
            for (int k = 0; k < arr2[0].size(); k++)
                answer[i][k] += arr1[i][j] * arr2[j][k];
    
    return answer;
}
