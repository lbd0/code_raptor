#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++){
        int count = 0; // i의 약수 개수
        
        for(int j = 1; j*j <= i; j++){ //대칭되는 숫자까지 한번에 계산. 이렇게 하지 않으면 시간 초과가 뜨네요....
            if (i % j == 0) {
                count++;
                if (j != i / j) //중복되는 약수 제외
                    count++;
            }
        }
        
        if (count > limit) count = power;
        answer += count;
    }
    
    return answer;
}
