#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int x;
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            x = i;
        }
    }
    answer = "김서방은 "+ to_string(x) +"에 있다";
    return answer;
}
