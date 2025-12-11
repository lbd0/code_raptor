#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "", back = "";
    
    // 음식의 개수만큼 반복
    for (int i = 1; i < food.size(); ++i) {
        // 현재 음식의 양을 저장
        int amount = food[i];
        
        // 현재 음식의 양을 두 선수에게 나누어 배치
        for (int j = 0; j < amount / 2; ++j) {
            answer += ('0' + i);
            back = char('0' + i) + back;
        }
    }
    
    return answer + '0' + back;
}
