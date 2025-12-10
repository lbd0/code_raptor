#include <string>
#include <vector>

using namespace std;

vector<string> split(string str)
{
    vector<string> res;
    int pos = 0, cur = 0;
    
    while((pos = str.find(" ", cur)) != string::npos)
    {
        string temp = str.substr(cur, pos-cur);
        res.push_back(temp);
        cur = pos + 1;
    }
    
    res.push_back(str.substr(cur));
    
    return res;
}

string solution(string s) {
    string answer = "";
    
    vector<string> sp = split(s);
    
    for(auto& s:sp)
    {
        for(int i=0; i<s.size(); ++i)
        {
            if(i%2==0)
            {
                if('a' <= s[i] && s[i] <= 'z') s[i] -= 32;
                answer += s[i];
            }
            else
            {
                if('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
                answer += s[i];
            }
        }
        answer += " ";
    }
    answer.erase(answer.size()-1);
    
    return answer;
}
