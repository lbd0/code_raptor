#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    
    map<string, int> mp = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    for (char ch : s) {
        if (isdigit(ch)) { //숫자일 경우
            answer = answer * 10 + (ch - '0'); //그냥 ch를 더하면 아스키 코드 값이 더해짐
        }
        else { // 문자일 경우
            tmp += ch;
            if (mp.find(tmp) != mp.end()) {
                answer = answer * 10 + mp[tmp];
                tmp = "";
            }
        }
    }
    return answer;
}
