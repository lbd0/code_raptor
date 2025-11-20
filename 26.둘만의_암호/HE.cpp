#include <string>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for(char c : s) {
        char x = c;
        int cnt = 0;

        while(cnt < index) {
            x++;
            if(x > 'z') x = 'a';
            if(skip.find(x) == string::npos) cnt++; // skip.find(x) : x가 skip에 있으면 위치 반환
        }

        answer += x;
    }

    return answer;
}
