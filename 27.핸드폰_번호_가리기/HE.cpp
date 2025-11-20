#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int n = phone_number.size();
  
    for(int i = 0; i < n - 4; i++){ // 이 부분 'string(n - 4, '*')'로 줄일 수 있다네요
        answer += '*';
    }
    answer += phone_number.substr(n - 4);
    
    return answer;
}
