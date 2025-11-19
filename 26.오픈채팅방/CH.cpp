#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> userInfo;
    queue<pair<string, string>> commands;
    vector<string> answer;
    
    for (const auto& r : record) {
        size_t start = r.find(" ");
        string command = r.substr(0, start);
        
        size_t end = r.find(" ", start + 1);
        string id = r.substr(start, end - start);
        
        if (command == "Enter") {
            commands.push({command, id});
            userInfo[id] = r.substr(end + 1);
        }
        else if (command == "Leave") {
            commands.push({command, id});
        }
        else {
            userInfo[id] = r.substr(end + 1);   
        }
    }
    
    while (!commands.empty()) {
        auto[command, id] = commands.front(); commands.pop();
        
        if (command == "Enter") answer.push_back(userInfo[id] + "님이 들어왔습니다.");
        else answer.push_back(userInfo[id] + "님이 나갔습니다.");
    }
    
    return answer;
}
