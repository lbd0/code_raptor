#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> logs;  // 로그 저장
    unordered_map<string, string> name; // 닉네임 저장

    for (const string& str : record) {
        stringstream ss(str);
        string state, id, nick;
        ss >> state >> id >> nick;

        if (state == "Enter") {
            name[id] = nick; // 닉네임 갱신
            logs.push_back({state, id});
        }
        else if (state == "Leave") {
            logs.push_back({state, id});
        }
        else {
            name[id] = nick; // 닉네임 변경
        }
    }

    for (auto& p : logs) {
        const string& state = p.first;
        const string& id = p.second;

        if (state == "Enter")
            answer.push_back(name[id] + "님이 들어왔습니다.");
        else
            answer.push_back(name[id] + "님이 나갔습니다.");
    }

    return answer;
}
