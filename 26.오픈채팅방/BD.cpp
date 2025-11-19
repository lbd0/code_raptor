#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// " " 기준으로 문자열 자르는 함수.
vector<string> split(string s)
{
    vector<string> res;
    
    int pos = 0;
    int cur = 0;
    
    while((pos =s.find(" ", cur)) != string::npos)
    {
        string temp = s.substr(cur, pos-cur);
        cur = pos + 1;
        
        res.push_back(temp);
    }
    
    res.push_back(s.substr(cur));
    
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // 들어왔는지 나갔는지 & uid 저장할 큐.
    queue<pair<bool, string>> timeline;
    
    // uid 별 닉네임 저장할 맵.
    unordered_map<string, string> name;
    
    for(auto& r:record)
    {
        vector<string> sp = split(r);
        bool isEnter = false;
        
        // change면 닉네임 변경.
        if(sp[0].compare("Change") == 0)
        {
            name[sp[1]] = sp[2];
            continue;
        }
        
        // enter면 들어온 거.
        if(sp[0].compare("Enter") == 0)
        {
            isEnter = true;
            name[sp[1]] = sp[2];
        }
        
         timeline.emplace(isEnter, sp[1]);
    
    }
    
    while(!timeline.empty())
    {
        pair<bool, string> temp = timeline.front();
        timeline.pop();
        
        string user = temp.second;
        string res = "";
        
        // 최종 닉네임 res에 추가.
        res += name[user];
        
        // 들어왔는지 나갔는지 확인하여 맞는 문구 추가.
        if(temp.first) res += "님이 들어왔습니다.";
        else res += "님이 나갔습니다.";
        
        answer.push_back(res);
    }
    
    return answer;
}
