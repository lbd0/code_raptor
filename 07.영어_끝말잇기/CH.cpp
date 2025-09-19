#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_map<string, int> count;
    
    // 이전 단어의 끝을 저장하기 위한 변수
    char prev = words[0].front();
    
    // words 크기만큼 반복
    for (int i = 0; i < words.size(); ++i)
    {
        // 중복 단어 혹은 이전 단어의 끝과 현재 단어의 앞이 다른 경우
        if (++count[words[i]] == 2 || prev != words[i][0])
        {
            // 차례와 라운드 수 저장
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            
            return answer;
        }
        
        // 현재 단어의 끝 저장
        prev = words[i].back();
    }

    return answer;
}
