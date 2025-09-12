#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    map<int, int> m1;
    int answer = -1; 
    int max = 0; //숫자 등장 횟수
    bool check = false; //최빈값 수 체크
    
    for (int n : array) {
        m1[n]++; 
    }

    for (auto a : m1) {
        if (a.second > max) { //m1의 값이 max보다 큰 경우
            max = a.second; //max 갱신
            answer = a.first; // 답은 m1의 키 값
            check = true;
        } else if (a.second == max) { //최빈값 중복
            check = false;
        }
    }

    if (!check)
        return -1;
    
    return answer;
}
