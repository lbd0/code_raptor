#include <vector>
#include <algorithm>

int solution(std::vector<int> wallet, std::vector<int> bill) {
    // 접는 횟수를 담을 변수 answer
    int answer = 0;
    
    // 지갑 크기를 오름차순으로 정렬
    std::sort(wallet.begin(), wallet.end());
    
    do
    {
        // 지폐 크기를 오름차순으로 정렬
        std::sort(bill.begin(), bill.end());
        
        // 지갑 크기와 지폐 크기를 비교
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1]) break;
        
        // 지폐 반 접기
        bill[1] /= 2;
        // 접은 횟수 증가
        ++answer;
    }
    while(true);
    
    // 접은 횟수 반환
    return answer;
}
