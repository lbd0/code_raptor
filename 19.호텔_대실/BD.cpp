#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
시간 => 분으로 변경.
시작 시각, 종료 시각 구분해서 저장.
시작 시각이 종료 시각+10보다 작으면 새로운 객실 필요한 것. answer++;
시작 시각이 종료 시각+10보다 크거나 같으면 기존 객실 사용 가능.
*/

// 시간 => 분 변경 함수.
int setTime(string str)
{
    int res = 0;
    int pos = 0;
    int cur = 0;
    
    while((pos = str.find(":", cur)) != string::npos)
    {
        res += stoi(str.substr(cur, pos-cur)) * 60;
        cur = pos + 1;
    }
    
    res += stoi(str.substr(cur));
    
    return res;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    
    // 시작 시각 벡터.
    vector<int> start;
    // 종료 시각 벡터.
    vector<int> end;
    
    // 시작, 종료 벡터에 시간 저장.
    for(auto& book:book_time)
    {
        start.push_back(setTime(book[0]));
        end.push_back(setTime(book[1]));
    }
    
    // 각각 내림차순 정렬.
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    // 필요한 객실 구하기.
    for(int i=1; i<start.size(); ++i)
    {
        // 새로운 객실 필요.
        if(start[i] < end.front()+10)
        {
            answer++;
        }
        else // 기존 객실 사용.
        {
            end.erase(end.begin());
        }
    }
    
    return answer;
}
