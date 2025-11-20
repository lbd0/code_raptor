#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for (int i = 0; i < signs.size(); ++i) answer += (signs[i] == true) ? absolutes[i] : absolutes[i] * (-1);
    
    return answer;
}
