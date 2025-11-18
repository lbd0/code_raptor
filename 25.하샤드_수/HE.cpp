#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = x;
    int s = 0;

    while(n > 0){
        s += n % 10;
        n = n / 10;
    }
    
    if(x % s != 0) answer = false;
    
    return answer;
}
