#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int c1 = 0, c2 = 0;
    
    for(const auto& g : goal) {
        if (cards1[c1] == g) ++c1;
        else if (cards2[c2] == g) ++c2;
        else return "No";
    }
    return "Yes";
}
