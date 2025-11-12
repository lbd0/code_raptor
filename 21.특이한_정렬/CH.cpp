#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        int dist1 = abs(a - n);
        int dist2 = abs(b - n);
        // 같은 거리라면 큰 수, 아니라면 거리가 작은 수
        return (dist1 == dist2) ? a > b : dist1 < dist2;
    });
    
    return numlist;
}
