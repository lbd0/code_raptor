#include <string>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int current_pos = 0;
    int pos = 0;
    
    // 처음부터 pat으로 끝나는 부분 문자열이 가장 김.
    // pat이 여러번 나올 수 있기 때문에, find로 계속 찾으면서 문자열 길이 비교.
    while((pos=myString.find(pat, current_pos)) != string::npos)
    {
        string temp = myString.substr(0, pos + pat.length());
        current_pos = pos + pat.length();
        
        answer = answer.length() < temp.length() ? temp:answer;
    }
    
    return answer;
}
