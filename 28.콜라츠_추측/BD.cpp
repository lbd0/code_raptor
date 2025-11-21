#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long long l_num = num;
    
    while(l_num != 1)
    {
        if(answer == 500) return -1;
        
        if(l_num%2 == 0) l_num /= 2;
        else l_num = (l_num * 3) + 1;
        
        answer++;
    }
    
    return answer;
}
