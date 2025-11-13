#include <string>
#include <vector>

using namespace std;

int fibo(int n) {
    if (n <= 1) return n;
    
    int x = 0, y = 1;
    
    for (int i = 2; i <= n; ++i) {
        long long temp = (x + y) % 1234567;
        x = y;
        y = temp;
    }
    
    return y;
}

int solution(int n) {
    return fibo(n);
}
