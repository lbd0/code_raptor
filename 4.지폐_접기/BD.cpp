/*
문제에서 주어진 의사 코드대로 작성함.
1. 지폐를 접은 횟수를 저장할 정수 변수 answer를 만들고 0을 저장합니다.
2. 반복문을 이용해 bill의 작은 값이 wallet의 작은 값 보다 크거나 bill의 큰 값이 wallet의 큰 값 보다 큰 동안 아래 과정을 반복합니다.
    2-1. bill[0]이 bill[1]보다 크다면
        bill[0]을 2로 나누고 나머지는 버립니다.
    2-2. 그렇지 않다면
        bill[1]을 2로 나누고 나머지는 버립니다.
    2-3. answer을 1 증가시킵니다.
3. answer을 return합니다.
*/

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int w_big, w_small, b_big, b_small;
    
    // 지갑 가로 세로 중 큰 수, 작은 수 저장.
    w_big = wallet[0] > wallet[1] ? wallet[0]:wallet[1];
    w_small = wallet[0] > wallet[1] ? wallet[1]:wallet[0];
    
    do
    {
        // 지폐 가로 세로 중 큰 수, 작은 수 저장.
        b_big = bill[0] > bill[1] ? bill[0]:bill[1];
        b_small = bill[0] > bill[1] ? bill[1]:bill[0];
        
        if(b_small <= w_small && b_big <= w_big) break;
        
        bill[0] > bill[1] ? bill[0]/=2 : bill[1]/=2;
        
        answer++;
        
    }while(true);
    return answer;
}
