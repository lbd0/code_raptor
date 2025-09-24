#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> lib;

    // 사전 초기화
    for (int i = 1; i <= 26; ++i) lib[string(1, 'A' + (i - 1))] = i;

    int i = 0;
    while (i < msg.size()) 
    {
        int len = 1;
        string key;

        // 가능한 가장 긴 문자열 찾기
        while (i + len <= msg.size() && lib.find(msg.substr(i, len)) != lib.end()) 
        {
            key = msg.substr(i, len);
            ++len;
        }

        answer.push_back(lib[key]);  // 정답 추가

        // 사전에 없는 문자열 등록
        if (i + len - 1 <= msg.size())
        {
            string str = msg.substr(i, len);
            lib[str] = lib.size() + 1;
        }

        i += key.size();  // 다음 시작 위치로 이동
    }

    return answer;
}
