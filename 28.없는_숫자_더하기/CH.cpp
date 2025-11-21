#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) {
    return (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9) - accumulate(numbers.begin(), numbers.end(), 0);
}
