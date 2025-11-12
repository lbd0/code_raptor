#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    sort(arr.begin(), arr.end());
    int del = arr[0];
    
    answer.erase(remove(answer.begin(), answer.end(), del), answer.end());
    
    if (answer.empty()) answer.push_back(-1);
    
    return answer;
}
