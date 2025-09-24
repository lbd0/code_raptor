// 풀이 참고
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;

    for (int i = 0; i < 26; i++)
        dict[string(1, 'A' + i)] = i + 1; // 사전에 A부터 Z까지 추가

    int idx = 27;
    int i = 0;
    while (i < msg.size()) {
        string w = "";
        int j = i;
      
        while (j < msg.size() && dict.find(w + msg[j]) != dict.end()) { //사전에 있는 문자일 경우
            w += msg[j];
            j++;
        }

        answer.push_back(dict[w]);

        if (j < msg.size())
            dict[w + msg[j]] = idx++; // 사전에 새로운 문자열 추가

        i += w.size(); // 다음 문자열로 이동
    }

    return answer;
}
