#include <string>

using namespace std;

string solution(string s) {
    // 단어의 몇번째 알파벳인지 저장할 변수
    int idx = 0;
    
    // 문자열 길이만큼 반복
    for (int i = 0; i < s.size(); ++i) {
        // 공백이 아닐 때
        if (s[i] != ' ') {
            // 짝수일 때 대문자로 바꾸기
            if (idx % 2 == 0) s[i] = toupper(s[i]);
            // 홀수일 때 소문자로 바꾸기
            else s[i] = tolower(s[i]);
            
            // 인덱스 증가
            ++idx;
        }
        // 공백이면 단어의 자릿수를 0으로 초기화
        else idx = 0;
    }
    
    return s;
}
