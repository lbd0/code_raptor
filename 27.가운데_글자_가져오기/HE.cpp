#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    
    if (n % 2 == 1) // 홀
        answer = s.substr(n / 2, 1);
    else // 짝
        answer = s.substr(n / 2 - 1, 2);

    return answer;
}
