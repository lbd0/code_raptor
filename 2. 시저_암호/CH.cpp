#include <string>

std::string solution(std::string s, int n) {
    for (char &c : s) {
        // 공백은 그대로 추가
        if (c == ' ') continue; 
        // 소문자일 경우
        else if (c >= 'a' && c <= 'z') c = (c - 'a' + n) % 26 + 'a';
        // 대문자일 경우
        else if (c >= 'A' && c <= 'Z') c = (c - 'A' + n) % 26 + 'A';
    }

    return s;
}
