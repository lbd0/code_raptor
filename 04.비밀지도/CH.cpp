#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    // 정답을 저장할 answer
    vector<string> answer;
    
    // n번 반복
    for (int i = 0; i < n; ++i)
    {
        string str;
        
        for (int j = n - 1; j >= 0; --j)
        {
            // 시프트 연산을 통해 1이면 #, 0이면 공백 저장
            str += ((arr1[i] >> j) & 1) || ((arr2[i] >> j) & 1) ? "#" : " ";
        }
        
        // 만들어진 str(한줄)을 answer에 저장
        answer.push_back(str);
    }
    
    return answer;
}
