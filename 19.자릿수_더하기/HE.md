#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int a = 1;
    
    while(n > 0){
        a = n % 10;
        answer += a;
        n = n / 10;
    }
    return answer;
}
