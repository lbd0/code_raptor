#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    // 0~9까지 저장
    vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < words.size(); ++i)
    {
        while(true)
        {  
            // 문자열 없으면 break
            if (s.find(words[i]) == string::npos) break;
            // 문자열을 인덱스 번호로 바꾸기
            s.replace(s.find(words[i]), words[i].length(), to_string(i));
        }
    }
    // 숫자로 바꿔 반환
    return stoi(s);
}
