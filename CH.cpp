#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.rbegin(), s.rend());
    return s;
}
