#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(!((bill[0] <= wallet[0] && bill[1] <= wallet[1]) || //지갑에 들어가는 크기가 될 때까지 반복
           (bill[0] <= wallet[1] && bill[1] <= wallet[0]))){
        
        if(bill[0] >= bill[1]) //길이가 긴 쪽을 접기
            bill[0] /= 2;
        else
            bill[1] /= 2;
        
        answer++;
    }
    
    return answer;
}
