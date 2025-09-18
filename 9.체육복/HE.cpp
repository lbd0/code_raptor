#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end()); //정렬
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) { // 여벌 체육복을 가져온 학생이 도난당했을 경우
                lost[i] = reserve[j] = 0; // 0으로 체크
                break; // 반복x
            }
        }
    }
    
    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] == 0) continue; // 0으로 체크된 건 넘김
      for (int j = 0; j < lost.size(); j++) {
            if (lost[j] == reserve[i] - 1 || lost[j] == reserve[i] + 1) {
                lost[j] = 0; // 체크
                break; // 반복x
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++){
        if (lost[i] != 0) // 전체 학생 수에서 못 빌린 학생 제외
            answer--;
    }
    

    return answer;
}
