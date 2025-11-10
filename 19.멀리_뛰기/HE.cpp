// n번째 경우의 수 : (n-1) + (n-2) 경우의 수 -> 피보나치 수열

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long num[2000];
    
    num[1] = 1;
    num[2] = 2;
    
    for(int i = 3; i <= n; i++) { 
        num[i] = (num[i-1] + num[i-2]) % 1234567; 
    }
    
    answer = num[n];

    return answer;
}
