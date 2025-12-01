#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> split(string s)
{
    vector<int> res;
    int pos = 0;
    int cur = 0;
    
    while((pos = s.find(" ", cur)) != string::npos)
    {
        string temp = s.substr(cur, pos-cur);
        res.push_back(stoi(temp));
        cur = pos + 1;
    }
    res.push_back(stoi(s.substr(cur)));
    
    return res;
}

string solution(string s) {
    string answer = "";
    
    vector<int> temp = split(s);
    
    sort(temp.begin(), temp.end());
    
    answer = to_string(temp[0]) + " " + to_string(temp[temp.size()-1]);
    
    return answer;
}
