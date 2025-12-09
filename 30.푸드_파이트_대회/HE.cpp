#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string s = "";
    
    for(int i = 1; i < food.size(); i++){
        int n = food[i] / 2;
        s += string(n, '0' + i); // i를 n번 붙임
    }
    string answer = s;
    reverse(s.begin(), s.end()); // 거꾸로
    answer += "0" + s; // 0 붙이고 s 반대로 붙이기
    
    return answer;
}
