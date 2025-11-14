#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int newcola; // 새로 받을 콜라
    
    while(n >= a){ 
        newcola = (n / a) * b;
        answer += newcola;
        n = (n % a) + newcola;
    }
    return answer;
}
