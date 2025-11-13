#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strnum;
    
    for (int n : numbers)
        strnum.push_back(to_string(n)); // 문자열로 변환
    
    sort(strnum.begin(), strnum.end(), [](string a, string b) { // 가장 큰 수가 될 조합으로 정렬
        return a + b > b + a;
    });

    for (string s : strnum)
        answer += s;
    
    if (answer[0] == '0') // 모든 원소가 0일 경우
        return "0";
    
    return answer;
}
