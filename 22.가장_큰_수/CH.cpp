#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> str;
    
    for (const auto& n : numbers) str.push_back(to_string(n));
    
    sort(str.begin(), str.end(), [](const string &a, const string& b) {
        return a + b > b + a;
    });
    
    if (str[0] == "0") return "0";
    
    string answer = "";
    for (const auto& s : str) answer += s;
    
    return answer;
}
