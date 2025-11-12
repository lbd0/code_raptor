#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
arr를 오름차순으로 정렬하면 0번째 값이 가장 작은 값 => 원래 배열에서 정렬한 배열의 0번째 값 제거하면 됨.
*/
vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) return {-1};

    vector<int> answer = arr;

    sort(arr.begin(), arr.end());
    
    answer.erase(remove(answer.begin(), answer.end(), arr[0]));
    
    return answer;
}
