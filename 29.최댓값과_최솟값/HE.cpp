#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string word;
    vector<int> numbers;
    
    while (ss >> word) { // 공백 기준으로 잘라서 numbers에 넣기
        numbers.push_back(stoi(word));
    }
    
    int min_n = *min_element(numbers.begin(), numbers.end());
    int max_n = *max_element(numbers.begin(), numbers.end());
    answer = to_string(min_n) + " " + to_string(max_n);
    
    return answer;
}
