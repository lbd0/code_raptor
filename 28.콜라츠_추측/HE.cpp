#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long n = num; // int 범위 때분에 오류가 난다
    int answer = 0;
    
    if(n == 1) return 0;
    
    while(n != 1){
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        
        answer++;
        
        if(answer > 500) return -1;
    }
    
    return answer;
}
