#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int i = 0, j = 0;
    
    for(string s : goal){ //goal 값 비교
        if (i < cards1.size() && cards1[i] == s) i += 1;
        else if (j < cards2.size() && cards2[j] == s) j += 1;
        else answer = "No";
    }
        
    return answer;
}
