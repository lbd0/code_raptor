#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 일수로 기간 넘었는지 확인하기.

// 문자열 나누는 함수.
vector<string> split(string str, string des)
{
    vector<string> res;
    
    int pos = 0;
    
    while((pos = str.find(des)) != string::npos)
    {
        string temp = str.substr(0, pos);
        
        res.push_back(temp);
        
        str.erase(0, pos+des.length());
        
    }
    
    res.push_back(str);
    
    return res;
}

// 년월일 -> 일로 변환하는 함수.
int calcDays(string& str)
{
    vector<string> date = split(str, ".");
    
    int year = stoi(date[0]);
    int month = stoi(date[1]);
    int day = stoi(date[2]);
    
    return year * 12 * 28 + month * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 오늘 날짜 -> 일수로 변환.
    int today_days = calcDays(today);
    
    // 약관 타입 저장.
    map<string, int> term_type;
    
    for(const auto& t:terms)
    {
        term_type[split(t, " ")[0]] = stoi(split(t, " ")[1]);
    }
    
    // 유효기간 일수로 변환하여 현재 일수랑 비교.
    for(int i=0; i<privacies.size(); ++i)
    {
        auto priv = split(privacies[i], " ");
        // 유효기간 일수 = 하루 빼야 함.
        int expire_days = calcDays(priv[0]) + term_type[priv[1]] * 28 -1;
        
        if(today_days > expire_days)
            answer.push_back(i+1);
        
    }
    
    return answer;
}
