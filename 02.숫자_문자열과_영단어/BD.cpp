#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    // 숫자 영단어 벡터
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int idx = 0;
    
    // 중복 숫자 때문에 이중 반복문 사용
    for(auto& num:numbers)
    {
        do
        {
            // num 문자열이 없으면 while 반복문 탈출
            if(s.find(num) == string::npos) break;
            
            // num 문자열 있으면 숫자로 바꾸기
            s.replace(s.find(num), num.size(), to_string(idx));
            
        }while(true);
        
        idx++;
    }
    
    answer = stoi(s);
    
    return answer;
}
