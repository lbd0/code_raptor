#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 10진수 -> 2진수 변환 함수.
string d2b(int s)
{
    string res = "";
    while(s>0)
    {
        res += to_string(s%2);
        s /= 2;
    }
    
    reverse(res.begin(), res.end());
        
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // 이진 변환 횟수 저장, 제거한 0 개수 저장.
    int cnt = 0, rcnt = 0;
    
    do
    {
        // s가 1이 되면 반복문 종료.
        if(s.compare("1") == 0) 
        {
            answer.push_back(cnt);
            answer.push_back(rcnt);
            break;
        }
        cnt++;
        
        // 제거할 0 개수 저장.
        rcnt += count(s.begin(), s.end(), '0');
        
        // 모든 0 제거.
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        
        // s의 길이 이진 변환 후 s로 저장.
        s = d2b(s.size());
        
    } while(true);
    
    return answer;
}
