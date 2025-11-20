#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int prev = section[0];
    
    for (int i = 1; i < section.size(); ++i) {
        if (section[i] - prev >= m) {
            prev = section[i];
            ++answer;
        }
    }
    
    return ++answer;
}
