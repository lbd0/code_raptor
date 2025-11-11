#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string ter; 
    
    while(n > 0){
        ter += to_string(n % 3); // 문자열로 저장
        n = n / 3;
    }
    int j = 1;
    
    for (int i = ter.size() - 1; i >= 0; i--) { 
        answer += (ter[i] - '0') * j; // 0 빼서 숫자로 바꿔주고 3 계산
        j *= 3;
    }
    return answer;
}
