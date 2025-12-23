#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    // accumulate : 구간의 속한 요소들의 합 구하는 함수. (first, last, init)
    double sum= accumulate(arr.begin(), arr.end(), 0.0);
    answer = sum / arr.size();
    return answer;
}
