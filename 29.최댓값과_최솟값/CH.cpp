#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> vt;
    
    int n = 0;
    bool isNegative = false;
    
    for (int i = 0; i <= s.size(); ++i) {
        // '-' 처리
        if (s[i] == '-') {
            isNegative = true;
        }
        // 숫자인 경우 누적
        else if (s[i] >= '0' && s[i] <= '9') {
            n = n * 10 + (s[i] - '0');
        }
        // 공백이거나 끝인 경우
        else if (s[i] == ' ' || i == s.size()) {
            if (isNegative) 
                n = -n;
            
            vt.push_back(n);
            
            // 초기화
            n = 0;
            isNegative = false;
        }
    }
    
    int min = vt[0], max = vt[0];
    for (const auto & v : vt) {
        if (min > v) min = v;
        if (max < v) max = v;
    }
    
    return to_string(min) + " " + to_string(max);
}
