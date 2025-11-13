#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 비교 함수를 이렇게도 쓸 수 있네요,, a+b로 합쳤을 때랑 b+a로 합쳤을 때 더 큰 수가 앞으로 정렬.
bool cmp(string a, string b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s_nums;
    
    for(auto& n:numbers)
    {
        s_nums.push_back(to_string(n));
    }
    
    sort(s_nums.begin(), s_nums.end(), cmp);
    
    for(auto& s:s_nums)
    {
        answer += s;
    }
    
    if(answer[0] == '0') answer = "0";
    
    return answer;
}
