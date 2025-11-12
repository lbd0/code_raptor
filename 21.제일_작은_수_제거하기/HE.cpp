#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    
    for (int i = 1; i < arr.size(); i++) { // 가장 작은 수 탐색
        if (arr[i] < min)
            min = arr[i];
    }

    for (int i = 0; i < arr.size(); i++) { // 가장 작은 수 제외하고 answer에 넣기
        if (arr[i] != min)
            answer.push_back(arr[i]);
    }
    
    if (arr.size() == 1) // 원소가 하나일 때 -1 반환
        return {-1}; // 리턴 타입이 달라서 {} 필요
    
    return answer;
}
