#include <string>

std::string solution(std::string myString, std::string pat) {
    // 뒤에서 부터 pat 찾기
    auto pos = myString.rfind(pat);
    
    if (pos == std::string::npos) return "";
    
    return myString.substr(0, pos + pat.size());
}
