#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (s != "1")
    {
        int cnt = 0;
        
        // 0, 1 개수 체크
        for (const auto& c : s)
        {
            if (c == '0') ++answer[1];
            else ++cnt;
        }
        
        // cnt 2진수로 변환
        string next = "";
        while (cnt > 0)
        {
            next += (cnt % 2) + '0';
            cnt /= 2;
        }
        
        reverse(next.begin(), next.end());
        s = move(next); // 복사보다 move가 빠름(gpt)
        ++answer[0];
    }
    
    return answer;
}
