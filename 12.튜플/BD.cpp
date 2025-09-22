#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// 튜플 원소의 순서에 따라 집합에 포함되는 개수가 다름.
// 예를 들어 [2,1,3,4] 튜플에서 2는 집합 4개{{2},{2,1},{2,1,3},{2,1,3,4}}에 포함되고, 4는 집합 1개{2,1,3,4}에 포함됨.


// 맵의 value 기준으로 내림차순 정렬.
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

// 문자열 나누기.
vector<string> split(string str, char de)
{
    istringstream iss(str);
    string buf;
    
    vector<string> res;
    
    while(getline(iss, buf, de))
    {
        res.push_back(buf);
    }
    
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // 집합에 포함되는 개수 저장할 맵.
    map<string, int> tuple;
    
    // 문자열 {} 지우고, , 기준으로 나누기.
    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    s.erase(remove(s.begin(), s.end(), '}'), s.end());
    
    vector<string> sp = split(s, ',');
    
    // 집합에 포함되는 개수 맵에 저장.
    for(const auto& a:sp)
    {
        tuple[a]++;
    }
    
    // value 기준으로 맵 내림차순 정렬.
    vector<pair<string, int>> temp(tuple.begin(), tuple.end());
    sort(temp.begin(), temp.end(), cmp);
    
    // value 기준 내림차순 정렬된 key 순서대로 answer에 저장.
    for(const auto& t:temp)
    {
        answer.push_back(stoi(t.first));
    }
    
    return answer;
}
