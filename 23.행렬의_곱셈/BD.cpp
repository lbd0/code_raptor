#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(auto& a1:arr1)
    {
        vector<int> temp;
        for(int i=0; i<arr2[0].size(); ++i)
        {
            int num = 0;
            for(int j=0; j<arr2.size(); ++j)
            {
                num += a1[j] * arr2[j][i];
            }
            temp.push_back(num);
        }
        answer.push_back(temp);
    }
        
        
    return answer;
}
