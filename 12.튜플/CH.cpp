#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

void countTuple(string & s, map<int, int> &tuples)
{
    // '{}' 지우기
    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    s.erase(remove(s.begin(), s.end(), '}'), s.end());
    
    // ','로 나누기
    stringstream ss(s);
    string item;
    
    // map에 넣기
    while (getline(ss, item , ','))
        ++tuples[stoi(item)];
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> tuples;
    
    countTuple(s, tuples);
    
    // 정렬을 위해 map -> vector
    vector<pair<int, int>> vec(tuples.begin(), tuples.end());
    
    // 정렬
    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    
    for (const auto& v : vec) answer.push_back(v.first);
    
    return answer;
}
